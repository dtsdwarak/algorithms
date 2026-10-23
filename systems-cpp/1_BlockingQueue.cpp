# include <bits/stdc++.h>

using namespace std;

template<typename T>
class BlockingQueue {
    
private:

    queue<T> queue_;
    condition_variable cv_;
    mutable mutex mutex_;
    bool shutdown_ = false;
    
public:
    
    BlockingQueue() = default;
    BlockingQueue(const BlockingQueue&) = delete;
    BlockingQueue& operator=(const BlockingQueue&) = delete;
    
    // lvalue based
    void push(const T& item) {
        {
            lock_guard<mutex> lock(mutex_);
            if (shutdown_) {
                throw runtime_error("shutdown invoked");
            }
            queue_.push(item);
        }
        cv_.notify_one();
    }
    
    
    // rvalue based
    void push(T&& item) {
        
        {
            lock_guard<mutex> lock(mutex_);
            if (shutdown_) {
                throw runtime_error("shutdown invoked");
            }
            queue_.push(move(item));
        }
        cv_.notify_one();
    }
    
    T pop() {
        
        unique_lock<mutex> lock(mutex_);
        cout<<"Waiting for lock acquisition"<<endl;
        
        // Wait until predicate is evaluated to be true.
        // Two scenarios posible to proceed further
        // 1. Queue is not empty. OR
        // 2. Shutdown is invoked.
        cv_.wait(lock, [&]{return !queue_.empty() || shutdown_;});
        
        if (shutdown_ && queue_.empty()) {
            cout<<"Nothing more to process. Quitting"<<endl;
            throw runtime_error("queue_shutdown");
        }
        
        // Lock acquired here.
        
        T item = move(queue_.front());
        queue_.pop();
        return item;
    }
    
    void shutdown() {
    
        {
            lock_guard<mutex> lock(mutex_);
            shutdown_ = true;
        }
        cv_.notify_all();
        
    }
};
    
    

/** === Program Logic === **/

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    BlockingQueue<int> queue_;
    
    thread producer([&] {
            {
                for (int i=0;i <10; i++)
                    queue_.push(i);
                queue_.shutdown();
            }
        });
        
    thread consumer([&] {
        try {
                
            while(true) {                                                                                                                                                                                                                                                                                           
                int value = queue_.pop();
                cout<<"Received value = "<<value<<endl;   
            }
            
        } catch (...) {
            cout<<"Queue processing complete";
        }
        
    });
    
    producer.join();
    consumer.join();
    
    
           
    getchar();
    return 0;
    
}
