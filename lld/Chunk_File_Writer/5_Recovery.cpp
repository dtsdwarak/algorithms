static std::vector<std::filesystem::path> loadManifest(const std::filesystem::path& dir) {
    std::vector<std::filesystem::path> segs;
    std::ifstream in(dir / "MANIFEST");
    if (!in) { // fallback: glob *.log
        for (auto& e : std::filesystem::directory_iterator(dir))
            if (e.path().extension() == ".log") segs.push_back(e.path());
        return segs;
    }
    std::string line;
    while (std::getline(in, line)) segs.push_back(dir / line);
    return segs;
}

static void salvageIfNeeded(const std::filesystem::path& seg) {
    std::ifstream in(seg, std::ios::binary);
    if (!in) return;
    // scan until we can’t read a full record; check for footer; if missing, truncate
    // (left as outline; in production: keep offsets and ftruncate)
}

