void writerLoop() {
    openNewFile();
    std::vector<std::string> batch;
    batch.reserve(100);

    while (true) {
        std::unique_lock lock(mutex_);
        cv_.wait_for(lock, std::chrono::milliseconds(100), [this] {
            return stop_ || !queue_.empty();
        });

        while (!queue_.empty()) {
            batch.push_back(std::move(queue_.front()));
            queue_.pop();
        }
        lock.unlock();

        for (const auto& msg : batch)
            file_ << msg << '\n';
        batch.clear();

        if (file_.tellp() >= static_cast<std::streampos>(maxSize_))
            rotate();

        if (stop_ && queue_.empty()) break;
    }
}

