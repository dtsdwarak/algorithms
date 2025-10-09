#include <map>
#include <functional>
#include <optional>

using Hash = uint64_t;

Hash hashKey(const std::string& key) {
    return std::hash<std::string>{}(key);
}

class ConsistentRing {
public:
    void addNode(const Node& n, int virtualNodeCount = 100) {
        for (int i = 0; i < virtualNodeCount; ++i) {
            std::string vnode = n.id + "#" + std::to_string(i);
            ring_[hashKey(vnode)] = n.id;
        }
        nodes_[n.id] = n;
    }

    void removeNode(const std::string& nodeId) {
        // naive remove: scan ring and delete entries for this nodeId
        for (auto it = ring_.begin(); it != ring_.end(); ) {
            if (it->second == nodeId) it = ring_.erase(it);
            else ++it;
        }
        nodes_.erase(nodeId);
    }

    // returns ordered candidate node ids (wrap-around)
    std::vector<std::string> candidates(const std::string& objectKey) const {
        std::vector<std::string> out;
        if (ring_.empty()) return out;

        Hash h = hashKey(objectKey);
        auto it = ring_.lower_bound(h);
        if (it == ring_.end()) it = ring_.begin();
        auto start = it;
        do {
            out.push_back(it->second);
            ++it;
            if (it == ring_.end()) it = ring_.begin();
        } while (it != start && out.size() < ring_.size());
        return out;
    }

    std::optional<Node> nodeById(const std::string& id) const {
        auto it = nodes_.find(id);
        if (it == nodes_.end()) return std::nullopt;
        return it->second;
    }

private:
    std::map<Hash, std::string> ring_;
    std::unordered_map<std::string, Node> nodes_;
};

