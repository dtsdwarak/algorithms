template <typename Key, typename Value>
class LockFreeCache {
public:
    void put(const Key& key, const Value& value) {
        std::lock_guard lock(write_mutex_);
        
        // Copy current map
        auto new_map = std::make_shared<std::unordered_map<Key, Value>>(
            *map_.load(std::memory_order_acquire)
        );
        
        // Modify copy
        (*new_map)[key] = value;
        
        // Atomically swap
        map_.store(new_map, std::memory_order_release);
    }
    
    std::optional<Value> get(const Key& key) const {
        // Lock-free read!
        auto snapshot = map_.load(std::memory_order_acquire);
        auto it = snapshot->find(key);
        return it != snapshot->end() ? std::optional(it->second) : std::nullopt;
    }

private:
    std::atomic<std::shared_ptr<std::unordered_map<Key, Value>>> map_{
        std::make_shared<std::unordered_map<Key, Value>>()
    };
    std::mutex write_mutex_; // Only for coordinating writers
};
