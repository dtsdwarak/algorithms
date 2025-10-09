#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

struct Node {
    std::string id;
    std::string rack;
    // capacity/weight could be added
};

std::vector<Node> placeReplicasSimple(const std::vector<Node>& nodes, size_t R) {
    std::vector<Node> selected;
    std::unordered_set<std::string> usedRacks;
    selected.reserve(R);

    // first pass: distinct racks
    for (const auto& n : nodes) {
        if (selected.size() >= R) break;
        if (!usedRacks.count(n.rack)) {
            selected.push_back(n);
            usedRacks.insert(n.rack);
        }
    }

    // second pass: fill quotas if not enough distinct racks
    for (const auto& n : nodes) {
        if (selected.size() >= R) break;
        bool already = false;
        for (const auto& s : selected) if (s.id == n.id) { already = true; break; }
        if (!already) selected.push_back(n);
    }

    return selected;
}

