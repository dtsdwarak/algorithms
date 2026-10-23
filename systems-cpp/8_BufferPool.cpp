# include <bits/stdc++.h>

using namespace std;

struct Page {
  
  uint64_t page_id;
  bool dirty = false;
  uint32_t pin_count = 0;
  vector<char> data;
  
  Page(uint64_t id): page_id(id), data(4096) {}
};

class BufferPool {

private:
    
    struct Entry {
        shared_ptr<Page> page;
        list<uint64_t>::iterator lru_position;
    };
    
    size_t capacity_;
    // Cache marking the order of page-access. Doubly linked list.
    list<uint64_t> lru_;
    // For lookup
    unordered_map<uint64_t, Entry> pages_;
    mutable mutex mutex_;W
    
    void evict_if_needed();

public:

    explicit BufferPool(size_t capacity): capacity_(capacity) {}
    shared_ptr<Page> get_page(uint64_t page_id);
    void release_page(shared_ptr<Page>);
    void mark_dirty(shared_ptr<Page>);
    void flush_page(shared_ptr<Page>);
    void flush_all();
    
};

void BufferPool::flush_page(shared_ptr<Page> page) {
    
    if (!page->dirty) {
        return;
    }    
    
    page->dirty = false;
    
}

void BufferPool::evict_if_needed() {
    
    while (pages_.size() >= capacity_) {
    
        auto victim = lru_.back();
        auto it = pages_.find(victim);
        
        // Verify active page via `pin_count` and `dirty` flag.
        if (it->second.page->pin_count > 0) {
            
            cout<<"Pin count > 0";
            
            lru_.pop_back();
            lru_.push_front(victim);
            continue;
        }
        
        if (it->second.page->dirty) {
            flush_page(it->second.page);
        }
        
        // Remove from cache
        lru_.pop_back();
        // Erase from lookup map
        pages_.erase(it);
    }
    
}

shared_ptr<Page> BufferPool::get_page(uint64_t page_id) {
    
    lock_guard<mutex> lock(mutex_);
    
    auto it = pages_.find(page_id);
    
    //Cache hit
    if (it != pages_.end()) {
    
        // Modify page access order
        lru_.erase(it->second.lru_position);
        lru_.push_front(it->first);
        it->second.lru_position = lru_.begin();
        
        // Nothing to update in the look up map.
        
        return it->second.page;
    }
    
    // Cache miss
    evict_if_needed();
    auto page = make_shared<Page>(page_id);
    
    lru_.push_front(page_id);
    pages_[page_id] = Entry{page, lru_.begin()};
    page->pin_count++;
    return page;
}

void BufferPool::mark_dirty(shared_ptr<Page> page) {
    page->dirty = true;
}




/** === Program Logic === **/

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    
           
    return 0;
    
}
