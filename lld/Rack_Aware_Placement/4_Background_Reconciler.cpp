#include <queue>
#include <functional>
#include <condition_variable>

class SimpleThreadPool {
public:
    SimpleThreadPool(size_t n) {
        for (size_t i = 0; i < n; ++i)
            workers_.emplace_back([this] { this->workerLoop(); });
    }
    ~SimpleThreadPool() {
        {
            std::unique_lock lk(mu_);
            stop_ = true;
        }
        cv_.notify_all();
        for (auto &t : workers_) t.join();
    }

    void submit(std::function<void()> fn) {
        {
            std::unique_lock lk(mu_);
            q_.push(std::move(fn));
        }
        cv_.notify_one();
    }
private:
    void workerLoop() {
        while (true) {
            std::function<void()> task;
            {
                std::unique_lock lk(mu_);
                cv_.wait(lk, [this]{ return stop_ || !q_.empty(); });
                if (stop_ && q_.empty()) return;
                task = std::move(q_.front()); q_.pop();
            }
            try { task(); } catch(...) { /* log and continue */ }
        }
    }
    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> q_;
    std::mutex mu_;
    std::condition_variable cv_;
    bool stop_{false};
};

