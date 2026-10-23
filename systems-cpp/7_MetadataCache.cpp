# include <bits/stdc++.h>

using namespace std;

struct Metadata {
  
  uint32_t uid;
  uint32_t gid;
  uint32_t permissions;
  uint64_t mtime;
  uint64_t size;
    
};

struct Entry {

    uint64_t inode;
    Metadata metadata;
};

class MetadataCache {

private:

    // To apply locks 
    mutable mutex mutex_;
    
    size_t capacity_;
    
    // Doubly linked list
    list<Entry> entries_;
    using ListIterator = list<Entry>::iterator;
    
    // Mapping between key and actual entry
    unordered_map<uint64_t, ListIterator> metadata_cache_;

public:
    
    explicit MetadataCache(size_t);
    optional<Metadata> lookup(uint64_t);
    void insert(uint64_t, Metadata);
    void invalidate(uint64_t);
    size_t size() const;
};


// Constructor
// explicit is only allowed as inline
MetadataCache::MetadataCache(size_t capacity):capacity_(capacity) {}

optional<Metadata> MetadataCache::lookup(uint64_t inode) {

    lock_guard<mutex> lock(mutex_);
    
    auto it = metadata_cache_.find(inode); //unordered_map<uint64_t,ListIterator>::iterator
    if (it == metadata_cache_.end()) {
        return nullopt;
    }
      
    // Now need to update the cache to make the inode most recently used
    entries_.splice(entries_.begin(),entries_,it->second);
    // metadata_cache_[inode] = entries_.begin(); // This is redundant.  
    
    return it->second->metadata;
}

void MetadataCache::insert(uint64_t inode, Metadata metadata) {

    lock_guard<mutex> lock(mutex_);
    
    unordered_map<uint64_t,ListIterator>::iterator it = metadata_cache_.find(inode);
    
    // Already exists. Just need to update position in cache
    if (it != metadata_cache_.end()) {
        entries_.splice(entries_.begin(), entries_, it->second);
        return;
    }
    
    // New entry
    entries_.push_front(Entry{inode, move(metadata)});
    metadata_cache_[inode] = entries_.begin();

    // Evict if capacity exceeds
    if (entries_.size() > capacity_) {
            
        metadata_cache_.erase(entries_.back().inode);
        entries_.pop_back();
        
    }
}

void MetadataCache::invalidate(uint64_t inode) {
    
    lock_guard<mutex> lock(mutex_);
    
    auto it = metadata_cache_.find(inode);
    if (it == metadata_cache_.end()) {
        return;
        //throw runtime_error("inode cache not found. Cannot invalidate");
    }
    
    entries_.erase(it->second);
    metadata_cache_.erase(it->first);
        
}

size_t MetadataCache::size() const {

   lock_guard<mutex> lock(mutex_);
   return entries_.size(); 
}

/** === Program Logic === **/

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    
           
    return 0;
    
}
