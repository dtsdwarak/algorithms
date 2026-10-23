/**

We will be creating a LRU cache, its aim is to be able to store values and evict the Least-Recently-Used ones if the capacity of the cache has been reached.

Create the following C++ class:

+------------------------------------------------------+
|                       LRUCache                       |
+------------------------------------------------------+
| - capacity_ : const std::size_t                      |
+------------------------------------------------------+
| + LRUCache(capacity : std::size_t)                   |
| + get(key : const std::string&)                      |
|      : std::optional<std::string>                    |
| + put(key : const std::string&, value : std::string) |
|      : void                                          |
| + size() const : std::size_t                         |
+------------------------------------------------------+
 */
 
#include <algorithm>
# include <bits/stdc++.h>
#include <mutex>
 
using namespace std;
 
class LRUCache {
  
  public:
    
    explicit LRUCache(size_t capacity): capacity_(capacity) {}
  
    optional<string> get(const string& key) {
        
        lock_guard<mutex> lock(mtx_);
        
        auto it = index_.find(key);
        if (it == index_.end()) {
            return nullopt;
        }
        
        // Move the used value to the front
        entries_.splice(entries_.begin(), entries_, it->second);
        
        return it->second->value;
    }
    
    void put (const string& key, string value) {
        
        lock_guard<mutex> lock(mtx_);
        
        if (capacity_ == 0) {
            cout<<"Null capacity";    
            return;
        }
        
        auto it = index_.find(key);
        
        // Already available 
        if (it != index_.end()) {
            
           it->second->value = move(value);
           entries_.splice(entries_.begin(), entries_, it->second); 
           return;
        }
        
        // New key
        entries_.push_front(Entry{key, move(value)});
        index_[key] = entries_.begin();
        
        // Evict if capacity is exceeded
        if (entries_.size() > capacity_) {
            index_.erase(entries_.back().key);
            entries_.pop_back();
        }
        
    }
    
    size_t size() const {
        
        lock_guard<mutex> lock(mtx_);
        return entries_.size();
    }
  
  private:
  
  const size_t capacity_;
  
    struct Entry {
        std::string key;
        std::string value;
    };

    using ListIterator = std::list<Entry>::iterator;
    // doubly linked list
    std::list<Entry> entries_;
    
    // key -> iterator for get calls
    std::unordered_map<std::string, ListIterator> index_;

    
    // Lock
    mutable mutex mtx_;
    
}; 
