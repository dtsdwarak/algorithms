#include <unordered_map>

struct KV {
    std::string value;
    bool tombstone;
    uint64_t seq; // logical timestamp if needed; here: file order
};

// very simplified reader that replays records from a segment into a map
static void replaySegment(const std::filesystem::path& seg, std::unordered_map<std::string, KV>& map, uint64_t baseSeq) {
    std::ifstream in(seg, std::ios::binary);
    if (!in) return;
    while (true) {
        uint32_t len;
        if (!in.read((char*)&len, 4)) break;
        std::string payload(len, '\0');
        if (!in.read(payload.data(), len)) break;

        size_t off = 0;
        bool tomb = payload[off++] != 0;
        uint32_t klen = *(uint32_t*)&payload[off]; off += 4;
        uint32_t vlen = *(uint32_t*)&payload[off]; off += 4;
        std::string key = payload.substr(off, klen); off += klen;
        std::string val = payload.substr(off, vlen);

        map[key] = KV{val, tomb, baseSeq++};
        // skip footer at end when hit (stop after a failed read)
    }
}

class Compactor {
public:
    static void compact(const std::filesystem::path& dir, const std::vector<std::filesystem::path>& segments) {
        std::unordered_map<std::string, KV> latest;
        uint64_t seq = 0;
        for (auto& s : segments) replaySegment(s, latest, seq += 1000000); // coarse seq bands per file

        // write compacted segment
        std::filesystem::path tmp = dir / "seg_compacted.log.open";
        std::ofstream out(tmp, std::ios::binary | std::ios::trunc);
        for (auto& [k, kv] : latest) {
            if (kv.tombstone) continue; // drop deletes
            writeRecord(out, Record{.key=k, .value=kv.value, .tombstone=false});
        }
        Footer f{}; out.write((char*)&f, sizeof(f));
        out.flush(); out.close();

        // atomically install: rename tmp to seg_XXXXX.log and update MANIFEST
        std::filesystem::path final = dir / "seg_compacted.log";
        std::filesystem::rename(tmp, final);
        fsyncDir(dir);

        // update MANIFEST atomically (write MANIFEST.new, fsync, rename → MANIFEST)
        writeManifest(dir, {final}); // keep only compacted segment for demo
    }

private:
    static void writeManifest(const std::filesystem::path& dir, const std::vector<std::filesystem::path>& active) {
        auto tmp = dir / "MANIFEST.new";
        std::ofstream m(tmp, std::ios::binary | std::ios::trunc);
        for (auto& p : active) m << p.filename().string() << "\n";
        m.flush(); m.close();
        std::filesystem::rename(tmp, dir / "MANIFEST");
        fsyncDir(dir);
    }
    static void fsyncDir(const std::filesystem::path& dir) {
        int d = ::open(dir.c_str(), O_DIRECTORY|O_RDONLY);
        if (d >= 0) { ::fsync(d); ::close(d); }
    }
};

