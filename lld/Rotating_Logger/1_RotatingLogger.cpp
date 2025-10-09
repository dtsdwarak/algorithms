#include <fstream>
#include <string>
#include <filesystem>

class RotatingLogger {
public:
    explicit RotatingLogger(std::string baseName, size_t maxSize = 1 << 20)
        : baseName_(std::move(baseName)), maxSize_(maxSize), index_(0) {
        openNewFile();
    }

    ~RotatingLogger() { file_.close(); }

    void log(const std::string& line) {
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

    std::string baseName_;
    size_t maxSize_;
    size_t index_;
    std::ofstream file_;
};

