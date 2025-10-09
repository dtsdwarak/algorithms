class BoundedThreadPool {
    public:
        BoundedThreadPool(size_t numThreads, size_t maxQueue)
            : stop_(false), maxQueue_(maxQueue) {
            for (size_t i = 0; i < numThreads; ++i) {
                workers_.emplace_back([this] { workerLoop(); });
            }
        }
    
        ~BoundedThreadPool() {
            {
                std::lock_guard<std::mutex> lock(mutex_);
                stop_ = true;
            }
            cv_.notify_all();
            for (auto &t : workers_) if (t.joinable()) t.join();
        }
    
        void enqueue(std::function<void()> task) {
            std::unique_lock<std::mutex> lock(mutex_);
            cv_full_.wait(lock, [this] { return tasks_.size() < maxQueue_ || stop_; });
            if (stop_) throw std::runtime_error("ThreadPool stopped");
            tasks_.push(std::move(task));
            cv_.notify_one();
        }
    
    private:
        void workerLoop() {
            while (true) {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(mutex_);
                    cv_.wait(lock, [this] { return stop_ || !tasks_.empty(); });
                    if (stop_ && tasks_.empty()) return;
                    task = std::move(tasks_.front());
                    tasks_.pop();
                    cv_full_.notify_one(); // signal space available
                }
                task();
            }
        }
    
        std::vector<std::thread> workers_;
        std::queue<std::function<void()>> tasks_;
        std::mutex mutex_;
        std::condition_variable cv_, cv_full_;
        std::atomic<bool> stop_;
        size_t maxQueue_;
    };
    