#include <queue>
#include <thread>
#include <condition_variable>
#include <atomic>

class AsyncLogger {
public:
    AsyncLogger(std::string baseName, size_t maxSize = 1 << 20)
        : baseName_(std::move(baseName)), maxSize_(maxSize), stop_(false) {
        worker_ = std::thread(&AsyncLogger::writerLoop, this);
    }

    ~AsyncLogger() {
        {
            std::lock_guard lock(mutex_);
            stop_ = true;
        }
        cv_.notify_all();
        if (worker_.joinable()) worker_.join();
        if (file_.is_open()) file_.close();
    }

    void log(const std::string& line) {
        {
            std::lock_guard lock(mutex_);
            queue_.push(line);
        }
        cv_.notify_one();
    }

private:
    void writerLoop() {
        openNewFile();
        while (true) {
            std::unique_lock lock(mutex_);
            cv_.wait(lock, [this] { return stop_ || !queue_.empty(); });

            if (stop_ && queue_.empty()) break;

            auto msg = std::move(queue_.front());
            queue_.pop();
            lock.unlock();

            file_ << msg << '\n';
            if (file_.tellp() >= static_cast<std::streampos>(maxSize_))
                rotate();
        }
    }

    void rotate() {
        file_.close();
        ++index_;
        openNewFile();
    }

    void openNewFile() {
        std::string filename = baseName_ + "." + std::to_string(index_) + ".txt";
        file_.open(filename, std::ios::out | std::ios::trunc);
    }

    std::mutex mutex_;
    std::condition_variable cv_;
    std::queue<std::string> queue_;
    std::thread worker_;
    std::atomic<bool> stop_;

    std::string baseName_;
    size_t maxSize_;
    size_t index_ = 0;
    std::ofstream file_;
};

