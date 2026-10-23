# include <bits/stdc++.h>

using namespace std;

template<typename K, typename V>
class ConcurrentHashMap {

private:
    
    struct Bucket {
        unordered_map<K, V> map_;
        mutable mutex mutex_;
    };
    vector<Bucket> buckets_;
    Bucket& bucket_for(const K& key) {
        size_t hash_value = hash<K>{}(key);
        return buckets_[hash_value % buckets_.size()];
    }

public:

    explicit ConcurrentHashMap(size_t num_buckets = 64) : buckets_(num_buckets) {}
        
    void put(const K& key, const V& value) {
    
        auto& bucket = bucket_for(key);
        
        // lock protection
        lock_guard<mutex> lock(bucket.mutex_);
        bucket.map_[key] = value;
    
    }
    
    
    bool get(const K& key, V& value) {
            
        auto& bucket = bucket_for(key);
        
        // Lock protection
        lock_guard<mutex> lock(bucket.mutex_);
        
        auto it = bucket.map_.find(key);
        if (it == bucket.map_.end()) {
            return false;
        }
        
        value = it->second_value;
        return true;
    }
    
    void erase(const K& key) {
    
        auto& bucket = bucket_for(key);
        lock_guard<mutex> lock(bucket.mutex_);
        
        auto it = bucket.map_.find(key);
        if (it == bucket.map_.end()) {
            throw runtime_error("key not found for erase operation");
        }
        
        bucket.map_.erase(key);
    }
    
};

/** === Program Logic === **/

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ConcurrentHashMap<string, int> concurrent_hashmap;
    concurrent_hashmap.put("a", 1);
    concurrent_hashmap.put("b", 2);
    concurrent_hashmap.put("c", 3);
    concurrent_hashmap.erase("b");
    try 
    {
        concurrent_hashmap.erase("d");
    } catch (const runtime_error& err) { // exception& err -> for catch all exceptions
        cout<<"Caught Exception"<<err.what()<<endl;
    }
           
    return 0;
    
}
