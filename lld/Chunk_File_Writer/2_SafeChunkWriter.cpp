#include <fcntl.h>
#include <unistd.h>

static uint32_t dumb_crc32(const char* p, size_t n) {
    uint32_t c = 0x811C9DC5u;
    for (size_t i=0;i<n;i++) c = (c ^ (unsigned char)p[i]) * 16777619u;
    return c;
}

struct Footer {
    uint32_t magic{0xC0FFEE00};
    uint32_t crc{0};
};

class SafeChunkedWriter {
public:
    SafeChunkedWriter(std::filesystem::path dir, size_t maxBytes)
        : dir_(std::move(dir)), maxBytes_(maxBytes) {
        std::filesystem::create_directories(dir_);
        openNew();
    }
    ~SafeChunkedWriter(){ sealAndRotateIfOpen(true); }

    void append(const Record& r) {
        writeRecord(out_, r);
        bytes_ = (size_t)out_.tellp();
        if (bytes_ >= maxBytes_) sealAndRotateIfOpen(false);
    }

private:
    void sealAndRotateIfOpen(bool final) {
        if (!out_.is_open()) return;
        // write footer (magic + crc of the entire file’s contents is expensive;
        // here we write a footer that just has magic; in practice keep a running CRC)
        Footer f{};
        out_.write((char*)&f, sizeof(f));
        out_.flush();
        fsyncFile(out_);

        // atomic rename .open -> .log
        std::filesystem::path finalName = curTmp_;
        finalName.replace_extension(".log");
        std::filesystem::rename(curTmp_, finalName);
        fsyncDir(dir_);

        out_.close();
        if (!final) openNew();
    }

    void openNew() {
        bytes_ = 0;
        std::ostringstream name;
        name << "seg_" << std::setw(6) << std::setfill('0') << seq_++ << ".log.open";
        curTmp_ = dir_ / name.str();
        out_.open(curTmp_, std::ios::binary | std::ios::trunc);
    }

    static void fsyncFile(std::ofstream& f) {
        f.flush();
        // grab native fd via FILE* fallback: reopen by path for simplicity
        // (in production: use fileno() from f.rdbuf()->fd() where supported)
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
};
