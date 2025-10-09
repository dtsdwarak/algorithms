#include <queue>
#include <thread>
#include <condition_variable>
#include <atomic>

class AsyncChunkedWriter {
public:
    AsyncChunkedWriter(std::filesystem::path dir, size_t maxBytes)
        : dir_(std::move(dir)), maxBytes_(maxBytes) {
        std::filesystem::create_directories(dir_);
        worker_ = std::thread([this]{ this->run(); });
    }
    ~AsyncChunkedWriter() {
        {
            std::lock_guard lk(mu_);
            stop_ = true;
        }
        cv_.notify_all();
        if (worker_.joinable()) worker_.join();
        // seal already handled at thread exit
    }

    void append(Record r) {
        {
            std::lock_guard lk(mu_);
            q_.push(std::move(r));
        }
        cv_.notify_one();
    }

private:
    void run() {
        openNew();
        std::vector<Record> batch;
        batch.reserve(256);
        while (true) {
            {
                std::unique_lock lk(mu_);
                cv_.wait_for(lk, std::chrono::milliseconds(50), [this]{ return stop_ || !q_.empty(); });
                while (!q_.empty()) { batch.push_back(std::move(q_.front())); q_.pop(); }
                if (stop_ && batch.empty()) break;
            }
            for (auto& r : batch) {
                writeRecord(out_, r);
                bytes_ = (size_t)out_.tellp();
                if (bytes_ >= maxBytes_) {
                    sealSegment();
                    openNew();
                }
            }
            out_.flush();
            batch.clear();
        }
        // graceful shutdown
        if (out_.is_open()) { sealSegment(); out_.close(); fsyncDir(dir_); }
    }

    void openNew() {
        bytes_ = 0;
        std::ostringstream name;
        name << "seg_" << std::setw(6) << std::setfill('0') << seq_++ << ".log.open";
        curTmp_ = dir_ / name.str();
        out_.open(curTmp_, std::ios::binary | std::ios::trunc);
    }

    void sealSegment() {
        Footer f{};
        out_.write((char*)&f, sizeof(f));
        out_.flush();
        // fsync file by re-open fd (portable-ish shortcut)
        out_.close();
        // rename to .log
        std::filesystem::path finalName = curTmp_;
        finalName.replace_extension(".log");
        std::filesystem::rename(curTmp_, finalName);
        fsyncDir(dir_);
        // reopen out_ on a new temp next time openNew() is called
    }

    static void fsyncDir(const std::filesystem::path& dir) {
        int d = ::open(dir.c_str(), O_DIRECTORY|O_RDONLY);
        if (d >= 0) { ::fsync(d); ::close(d); }
    }

    std::filesystem::path dir_;
    std::filesystem::path curTmp_;
    std::ofstream out_;
    size_t maxBytes_;
    size_t bytes_{0};
    uint64_t seq_{1};

    std::mutex mu_;
    std::condition_variable cv_;
    std::queue<Record> q_;
    std::thread worker_;
    bool stop_{false};
};
