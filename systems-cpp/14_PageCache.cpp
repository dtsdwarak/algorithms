/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

using namespace std;

struct PageKey
{
    uint64_t file_id;
    uint64_t offset;

    bool operator==(const PageKey& other) const
    {
        return file_id == other.file_id && offset == other.offset;
    }
};

struct Hash
{
    size_t operator()(const PageKey& k) const
    {
        return std::hash<uint64_t>{}(k.file_id)^(std::hash<uint64_t>{}(k.offset)<< 1);
    }
};

class PageCache
{
private:

    struct Entry
    {
        std::shared_ptr<Page> page;
        std::list<PageKey>::iterator lru_it;
    };

    size_t capacity_;

    std::unordered_map<PageKey,Entry,Hash> cache_;
    std::list<PageKey> lru_;
    std::mutex mutex_;

public:

    explicit PageCache(size_t capacity): capacity_(capacity){}

    std::shared_ptr<Page> lookup(uint64_t file_id,uint64_t offset)
    {

        std::lock_guard<std::mutex>lock(mutex_);
        PageKey key{file_id,offset};

        auto it = cache_.find(key);

        if (it == cache_.end())
        {
            return nullptr;
        }

        promote(it);

        ++it->second.page->refcount;

        return it->second.page;

    }

    void insert(uint64_t file_id,uint64_t offset,std::shared_ptr<Page> page)
    {

        std::lock_guard<std::mutex> lock(mutex_);
        evict_if_needed();
        PageKey key{file_id,offset};

        lru_.push_front(key);

        cache_[key] = {
            page,
            lru_.begin()
        };
    }

    void mark_dirty(std::shared_ptr<Page> page)
    {
        page->dirty = true;
    }

    void release(std::shared_ptr<Page> page)
    {
        if (page->refcount > 0)
        {
            --page->refcount;
        }
    }

private:

    void evict_if_needed()
    {
        while (cache_.size() >=capacity_)
        {
            auto victim = lru_.back();

            auto it = cache_.find(victim);
            if (it->second.page->refcount > 0)
            {
                break;
            }

            if (it->second.page->dirty)
            {
                flush(it->second.page);
            }

            lru_.pop_back();
            cache_.erase(it);

            return;
        }
    }

    void flush(std::shared_ptr<Page> page)
    {
        /*
         * simulate disk write
         */
        page->dirty = false;
    }

    void promote(typename std::unordered_map<PageKey,Entry,Hash>::iterator it)
    {
        lru_.erase(it->second.lru_it);
        lru_.push_front(it->first);
        it->second.lru_it = lru_.begin();
    }

};
