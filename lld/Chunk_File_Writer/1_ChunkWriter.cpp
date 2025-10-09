#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <iomanip>
#include <sstream>

struct Record {
    std::string key;
    std::string value;     // if value == "" and tombstone=true => delete
    bool tombstone{false};
};

// naive length-prefix framing: [len32][tomb1][key_len32][val_len32][key][val]
static void writeRecord(std::ofstream& out, const Record& r) {
    auto u32 = [](uint32_t x){ return x; };
    std::string payload;
    payload.reserve(9 + r.key.size() + r.value.size());
    // pack into payload (very simple; no endianness conversions shown)
    uint32_t klen = (uint32_t)r.key.size();
    uint32_t vlen = (uint32_t)r.value.size();
    payload.push_back(r.tombstone ? '\1' : '\0');
    payload.append((char*)&klen, 4);
    payload.append((char*)&vlen, 4);
    payload.append(r.key);
    payload.append(r.value);

    uint32_t len = (uint32_t)payload.size();
    out.write((char*)&len, 4);
    out.write(payload.data(), payload.size());
}

class ChunkedWriter {
public:
    ChunkedWriter(std::filesystem::path dir, size_t maxBytes)
        : dir_(std::move(dir)), maxBytes_(maxBytes) {
        std::filesystem::create_directories(dir_);
        openNew();
    }
    ~ChunkedWriter(){ if (out_.is_open()) out_.close(); }

    void append(const Record& r) {
        if (!out_.is_open()) openNew();
        writeRecord(out_, r);
        bytes_ = (size_t)out_.tellp();
        if (bytes_ >= maxBytes_) rotate();
    }
private:
    void rotate() {
        out_.flush();
        out_.close();
        ++seq_;
        openNew();
    }
    void openNew() {
        bytes_ = 0;
        std::ostringstream name;
        name << "seg_" << std::setw(6) << std::setfill('0') << seq_ << ".log.open";
        curTmp_ = dir_ / name.str();
        out_.open(curTmp_, std::ios::binary | std::ios::trunc);
    }

    std::filesystem::path dir_;
    std::filesystem::path curTmp_;
    std::ofstream out_;
    size_t maxBytes_;
    size_t bytes_{0};
    uint64_t seq_{1};
};
