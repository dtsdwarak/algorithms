# include <bits/stdc++.h>

using namespace std;

class LeakyBucket {
  
private:
    
    const double capacity_;
    const double leak_rate_;
    chrono::steady_clock::time_point last_leak_time_;
    
    double pending_requests_;
    mutable mutex mutex_;

    void leak();
    
public:

    LeakyBucket(size_t capacity, double leak_rate): capacity_(capacity), leak_rate_(leak_rate), last_leak_time_(chrono::steady_clock::now()),pending_requests_(0) {}
    bool allow();
};

void LeakyBucket::leak() {

    chrono::steady_clock::time_point time_now = chrono::steady_clock::now();
    auto elapsed_time = time_now - last_leak_time_;
    
    double extra_leak = elapsed_time.count() * leak_rate_;
    pending_requests_ = max(0.0,pending_requests_-extra_leak);
    
    last_leak_time_ = time_now;
}

bool LeakyBucket::allow() {
    
    lock_guard<mutex> lock(mutex_);
    leak();
    
    if (pending_requests_ >= capacity_)
        return false;
        
    pending_requests_ += 1.0;    
    
    return true;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    
           
    return 0;
    
}
