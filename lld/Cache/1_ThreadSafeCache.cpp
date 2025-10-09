#include <unordered_map>
#include <shared_mutex>
#include <optional>

template <typename Key, typename Value>
class ThreadSafeCache {
public:
    void put(const Key& key, const Value& value) {
        std::unique_lock lock(mutex_); // exclusive for writes
        cache_[key] = value;
    }

    std::optional<Value> get(const Key& key) const {
        std::shared_lock lock(mutex_); // shared for reads
        if (auto it = cache_.find(key); it != cache_.end())
            return it->second;
        return std::nullopt;
    }

    void erase(const Key& key) {
        std::unique_lock lock(mutex_);
        cache_.erase(key);
    }

private:
    mutable std::shared_mutex mutex_;
    std::unordered_map<Key, Value> cache_;
};

