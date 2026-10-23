# include <bits/stdc++.h>

using namespace std;

template<typename T>
class ObjectPool {
  
private:

    queue<unique_ptr<T>> pool_;
    mutable mutex mutex_;
    
public:
    
    ObjectPool()=default;
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
    size_t available();
};

template<typename T>
unique_ptr<T> ObjectPool<T>::acquire() {

    {
        lock_guard<mutex> lock(mutex_);

        if (!pool_.empty()) {
            unique_ptr<T> obj = move(pool_.front());
            pool_.pop();
            return obj;    
        }
    }
    
    return make_unique<T>();
    //return unique_ptr<T>(new T());
}

template<typename T>
void ObjectPool<T>::release(unique_ptr<T> obj) {
    
    if (!obj) {
        return;
    }
    
    lock_guard<mutex> lock(mutex_);
    pool_.push(move(obj));
}

template<typename T>
size_t ObjectPool<T>::available() const {
    
    lock_guard<mutex> lock(mutex_);
    return pool_.size();
}

/** === Program Logic === **/

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    
           
    return 0;
    
}
