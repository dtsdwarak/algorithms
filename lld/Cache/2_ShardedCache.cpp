#include <vector>
#include <functional>

template <typename Key, typename Value, size_t NumShards = 8>
class ShardedCache {
public:
    void put(const Key& key, const Value& value) {
        auto& shard = getShard(key);
        std::unique_lock lock(shard.mutex);
        shard.map[key] = value;
    }

    std::optional<Value> get(const Key& key) const {
        auto& shard = getShard(key);
        std::shared_lock lock(shard.mutex);
        if (auto it = shard.map.find(key); it != shard.map.end())
            return it->second;
        return std::nullopt;
    }

    void erase(const Key& key) {
        auto& shard = getShard(key);
        std::unique_lock lock(shard.mutex);
        shard.map.erase(key);
    }

private:
    struct Shard {
        mutable std::shared_mutex mutex;
        std::unordered_map<Key, Value> map;
    };

    std::array<Shard, NumShards> shards_;

    Shard& getShard(const Key& key) const {
        size_t idx = std::hash<Key>{}(key) % NumShards;
        return const_cast<Shard&>(shards_[idx]);
    }
};

