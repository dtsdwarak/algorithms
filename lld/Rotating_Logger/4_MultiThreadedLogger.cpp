#include <vector>

class MultiThreadedLogger {
public:
    MultiThreadedLogger(std::string baseName, size_t maxSize = 1 << 20, size_t numWorkers = 2)
        : baseName_(std::move(baseName)), maxSize_(maxSize), stop_(false) {
        for (size_t i = 0; i < numWorkers; ++i)
            workers_.emplace_back(&MultiThreadedLogger::writerLoop, this, i);
    }

    ~MultiThreadedLogger() {
        {
            std::lock_guard lock(mutex_);
            stop_ = true;
        }
        cv_.notify_all();
        for (auto& w : workers_) if (w.joinable()) w.join();
    }

    void log(const std::string& line) {
        {
            std::lock_guard lock(mutex_);
            queue_.push(line);
        }
        cv_.notify_one();
    }

private:
    void writerLoop(size_t workerId) {
        std::ofstream file(baseName_ + "." + std::to_string(workerId) + ".txt");
        while (true) {
            std::unique_lock lock(mutex_);
            cv_.wait(lock, [this] { return stop_ || !queue_.empty(); });
            if (stop_ && queue_.empty()) break;

            auto msg = std::move(queue_.front());
            queue_.pop();
            lock.unlock();

            file << msg << '\n';
        }
    }

    std::mutex mutex_;
    std::condition_variable cv_;
    std::queue<std::string> queue_;
    std::vector<std::thread> workers_;
    std::atomic<bool> stop_;
    std::string baseName_;
    size_t maxSize_;
};

