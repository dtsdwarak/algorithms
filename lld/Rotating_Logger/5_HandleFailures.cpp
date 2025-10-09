void safeWrite(std::ofstream& file, const std::string& msg) {
    try {
        file << msg << '\n';
        if (!file.good())
            throw std::ios_base::failure("Write failed");
    } catch (const std::exception& e) {
        // fallback: buffer in memory
        std::lock_guard lock(errorMutex_);
        errorBuffer_.push_back(msg);
    }
}

