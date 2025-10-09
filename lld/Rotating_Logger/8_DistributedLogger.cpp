class DistributedLogger {
public:
    void log(const std::string& line) {
        std::lock_guard lock(mutex_);
        buffer_.push_back(line);
        if (buffer_.size() >= batchSize_)
            flushToRemote();
    }

private:
    void flushToRemote() {
        // pseudo-code: send via socket or RPC
        for (const auto& msg : buffer_)
            sendOverNetwork(msg);
        buffer_.clear();
    }

    void sendOverNetwork(const std::string& msg) {
        // simulate network write
    }

    std::mutex mutex_;
    std::vector<std::string> buffer_;
    size_t batchSize_ = 100;
};

