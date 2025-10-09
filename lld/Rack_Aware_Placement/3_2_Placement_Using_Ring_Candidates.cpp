std::vector<Node> placeUsingRing(const ConsistentRing& ring, const std::string& key, size_t R) {
    auto candIds = ring.candidates(key);
    std::vector<Node> selected;
    std::unordered_set<std::string> usedRacks;
    for (const auto& id : candIds) {
        if (selected.size() >= R) break;
        if (auto nopt = ring.nodeById(id); nopt) {
            if (!usedRacks.count(nopt->rack)) {
                selected.push_back(*nopt);
                usedRacks.insert(nopt->rack);
            }
        }
    }
    // if not enough distinct racks, pick other candidates ignoring rack
    for (const auto& id : candIds) {
        if (selected.size() >= R) break;
        if (auto nopt = ring.nodeById(id); nopt) {
            bool already = false;
            for (auto const& s : selected) if (s.id == nopt->id) { already = true; break; }
            if (!already) selected.push_back(*nopt);
        }
    }
    return selected;
}

