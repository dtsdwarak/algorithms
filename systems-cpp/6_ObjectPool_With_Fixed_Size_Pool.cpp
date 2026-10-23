# include <bits/stdc++.h>

using namespace std;

template<typename T>
class ObjectPool {
  
private:

    queue<unique_ptr<T>> pool_;
    mutable mutex mutex_;
    condition_variable cv_;
    
public:
    
    explicit ObjectPool(size_t pool_size=10) {
    
        for(size_t i = 0; i<pool_size; i++) {
            pool_.push(make_unique<T>());
        }
    }
    // Disable copy constructor
    ObjectPool(const ObjectPool&)=delete;
    // Disable copy assignment operator
    ObjectPool& operator=(const ObjectPool&)=delete;
    
    // Disable move constructor
    ObjectPool(ObjectPool&&)=delete;
    // Disable move assignment operator
    ObjectPool& operator=(ObjectPool&&)=delete;
    
    unique_ptr<T> acquire();
    void release(unique_ptr<T>);
    size_t available() const;
};

template<typename T>
unique_ptr<T> ObjectPool<T>::acquire() {
    
    unique_lock<mutex> lock(mutex_);
    cv_.wait(lock, [this] { return !pool_.empty(); });

    unique_ptr<T> obj = move(pool_.front());
    pool_.pop();
    return obj;    
}

template<typename T>
void ObjectPool<T>::release(unique_ptr<T> obj) {
    
    if (!obj) {
        return;
    }
    
    lock_guard<mutex> lock(mutex_);
    pool_.push(move(obj));
    
    cv_.notify_one();
}

template<typename T>
size_t ObjectPool<T>::available() const {
    
    lock_guard<mutex> lock(mutex_);
    return pool_.size();
}

/** === Program Logic === **/

struct RandomObject {
    
    string name;
    int value;
};

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ObjectPool<RandomObject> pool_;
    
    unique_ptr<RandomObject> obj = pool_.acquire();
    pool_.release(move(obj));
    
           
    return 0;
    
}
