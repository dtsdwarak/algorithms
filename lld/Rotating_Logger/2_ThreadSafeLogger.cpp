#include <mutex>

class ThreadSafeLogger {
public:
    explicit ThreadSafeLogger(std::string baseName, size_t maxSize = 1 << 20)
        : baseName_(std::move(baseName)), maxSize_(maxSize), index_(0) {
        openNewFile();
    }

    ~ThreadSafeLogger() { file_.close(); }

    void log(const std::string& line) {
        std::lock_guard lock(mutex_); // Serialize access
        if (!file_.is_open()) openNewFile();
        file_ << line << '\n';
        if (file_.tellp() >= static_cast<std::streampos>(maxSize_))
            rotate();
    }

private:
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
    std::string baseName_;
    size_t maxSize_;
    size_t index_;
    std::ofstream file_;
};

