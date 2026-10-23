# include <bits/stdc++.h>

using namespace std;

template <typename T>
class ProducerConsumerQueue {
  
private:
    
    queue<T> queue_;
    mutable mutex mutex_;
    condition_variable not_full_cv_;
    condition_variable not_empty_cv_;
    size_t capacity_;
    bool shutdown_;
    
    
public:

    explicit ProducerConsumerQueue(size_t capacity):capacity_(capacity), shutdown_(false) {}
    
    ProducerConsumerQueue(const ProducerConsumerQueue&)=delete;
    ProducerConsumerQueue& operator=(const ProducerConsumerQueue&)=delete;
    
    ProducerConsumerQueue(ProducerConsumerQueue&&)=delete;
    ProducerConsumerQueue& operator=(ProducerConsumerQueue&&)=delete;
    
    void push(T obj);
    T pop();
    size_t size() const;
    void shutdown();
};


template<typename T>
void ProducerConsumerQueue<T>::push(T obj) {
    
    unique_lock<mutex> lock(mutex_);
    
    not_full_cv_.wait(lock, [this]{ return queue_.size() < capacity_ || shutdown_; });
    

    if (shutdown_) {
        throw runtime_error("Queue shutdown. Can't push");
    }
    
    queue_.push(move(obj));
    
    // lock.unlock(); -> optimal
    
    // Notify consumer
    not_empty_cv_.notify_one();
    
}

template<typename T>
T ProducerConsumerQueue<T>::pop() {
    
    unique_lock<mutex> lock(mutex_);
    
    not_empty_cv_.wait(lock, [this] { return !queue_.empty() || shutdown_; });
    
    // Only shutdown when queue is also empty. Otherwise, consume
    if (shutdown_ && queue_.empty()) {
        throw runtime_error("Queue shutdown. Can't pop");
    }
    
    T obj = move(queue_.front());
    queue_.pop();
    
    // lock.unlock(); -> optimal
    
    // Notify producer.
    not_full_cv_.notify_one();
    
    return obj;
}

template<typename T>
size_t ProducerConsumerQueue<T>::size() const {

    lock_guard<mutex> lock(mutex_);
    return queue_.size();
    
}

template<typename T>
void ProducerConsumerQueue<T>::shutdown() {

    {
        lock_guard<mutex> lock(mutex_);
        shutdown_ = true;
    }
    not_empty_cv_.notify_all();
    not_full_cv_.notify_all();
}

/** === Program Logic === **/

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    
           
    return 0;
    
}
