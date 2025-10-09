#include <shared_mutex>
#include <unordered_map>
#include <optional>

class ClusterState {
public:
    void addNode(const Node& n) {
        std::unique_lock lock(mutex_);
        nodes_[n.id] = n;
        // optionally maintain rack -> vector mapping for faster selects
    }

    void removeNode(const std::string& nodeId) {
        std::unique_lock lock(mutex_);
        nodes_.erase(nodeId);
    }

    std::vector<Node> snapshotNodes() const {
        std::shared_lock lock(mutex_);
        std::vector<Node> out;
        out.reserve(nodes_.size());
        for (auto const& p : nodes_) out.push_back(p.second);
        return out;
    }

    std::optional<Node> getNode(const std::string& id) const {
        std::shared_lock lock(mutex_);
        auto it = nodes_.find(id);
        if (it == nodes_.end()) return std::nullopt;
        return it->second;
    }

private:
    mutable std::shared_mutex mutex_;
    std::unordered_map<std::string, Node> nodes_;
};

