class LRUCache {

    struct Item {
        int key;
        int value;
    };

    const size_t capacity_;

    list<Item> cache_;
    using ListIterator = list<Item>::iterator;

    unordered_map<int, ListIterator> index_; // key -> index;

public:
    LRUCache(int capacity):capacity_(capacity) {}
    
    int get(int key) {
        

        auto it = index_.find(key);
        if (it == index_.end())
            return -1;
        
        cache_.splice(cache_.begin(), cache_, it->second);

        return it->second->value;
    }
    
    void put(int key, int value) {

        
        auto it = index_.find(key);

        // Already available
        if (it != index_.end()) {
            
            it->second->value = value;
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }

        // New key
        cache_.push_front(Item{key, value});
        index_[key] = cache_.begin();


        // If capacity is exceeded
        if (cache_.size() > capacity_) {
            index_.erase(cache_.back().key);
            cache_.pop_back();
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
