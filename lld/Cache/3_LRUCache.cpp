#include <list>
#include <unordered_map>
#include <mutex>
#include <optional>

template <typename Key, typename Value>
class LRUCache {
public:
    explicit LRUCache(size_t capacity) : capacity_(capacity) {}

    std::optional<Value> get(const Key& key) {
        std::lock_guard lock(mutex_);
        if (auto it = map_.find(key); it != map_.end()) {
            // move key to front (most recently used)
            order_.splice(order_.begin(), order_, it->second.second);
            return it->second.first;
        }
        return std::nullopt;
    }

    void put(const Key& key, const Value& value) {
        std::lock_guard lock(mutex_);
        if (auto it = map_.find(key); it != map_.end()) {
            it->second.first = value;
            order_.splice(order_.begin(), order_, it->second.second);
        } else {
            if (map_.size() >= capacity_) {
                auto last = order_.back();
                map_.erase(last);
                order_.pop_back();
            }
            order_.push_front(key);
            map_[key] = {value, order_.begin()};
        }
    }

private:
    mutable std::mutex mutex_;
    size_t capacity_;
    std::list<Key> order_; // MRU at front
    std::unordered_map<Key, std::pair<Value, typename std::list<Key>::iterator>> map_;
};

