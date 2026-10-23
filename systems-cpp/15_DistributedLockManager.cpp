/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

using namespace std;

class DistributedLockManager
{
private:
    struct LockState
    {

        uint64_t owner;
        uint64_t token;
        std::chrono::steady_clock::time_point expiry;
    };

    std::unordered_map<uint64_t,LockState> locks_;
    uint64_t next_token_ = 1;
    std::mutex mutex_;

public:

    bool acquire(uint64_t resource,uint64_t client,std::chrono::seconds ttl = std::chrono::seconds(30))
    {
        std::lock_guard<std::mutex> lock(mutex_);

        auto now = std::chrono::steady_clock::now();
        auto it = locks_.find(resource);

        /*
         * Lock already owned and valid.
         */
        if (it != locks_.end() && it->second.expiry > now)
        {
            return false;
        }

        locks_[resource] =
        {
            client,
            next_token_++,
            now + ttl
        };

        return true;
    }

    void release(uint64_t resource,uint64_t client)
    {

        std::lock_guard<std::mutex> lock(mutex_);
        auto it = locks_.find(resource);

        if (it != locks_.end() && it->second.owner == client)
        {
            locks_.erase(it);
        }
    }

    bool renew(uint64_t resource, uint64_t client)
    {
        std::lock_guard<std::mutex> lock(mutex_);

        auto it = locks_.find(resource);
        if ( it == locks_.end() || it->second.owner != client)
        {
            return false;
        }

        it->second.expiry = std::chrono::steady_clock::now() + std::chrono::seconds(30);

        return true;
    }

    bool is_owner(uint64_t resource, uint64_t client)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = locks_.find(resource);

        return it != locks_.end() && it->second.owner== client;
    }

};
