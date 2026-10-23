# include <bits/stdc++.h>

using namespace std;

class SlidingWindowBucket {

private:
        size_t previous_window_count_;
        size_t current_window_count_;
        const chrono::seconds window_size_;
        const size_t rate_limit_;
        chrono::steady_clock::time_point current_window_start_;
        mutex mutex_;
        
        void slide_windows();
        
public:
    
    SlidingWindowBucket(size_t rate_limit, chrono::seconds window_size) : rate_limit_(rate_limit), window_size_(window_size), previous_window_count_(0), current_window_count_(0), current_window_start_(chrono::steady_clock::now()) {}
    
    bool allow();

    
};

void SlidingWindowBucket::slide_windows() {


    chrono::steady_clock::time_point time_now = chrono::steady_clock::now();
    auto time_elapsed = time_now - current_window_start_;
    
    auto elapsed_windows = time_elapsed/window_size_;
    
    if (elapsed_windows == 0) {
        return;
    } 
    else if (elapsed_windows == 1) {
        previous_window_count_ = current_window_count_;
        current_window_count_ = 0;
    } 
    else {
        previous_window_count_ = 0;
        current_window_count_ = 0;
    }
    
    current_window_start_ += elapsed_windows*window_size_;
}

bool SlidingWindowBucket::allow() {
    
    lock_guard<mutex> lock(mutex_);
    slide_windows();
    
    chrono::steady_clock::time_point time_now = chrono::steady_clock::now();
    auto time_elapsed = time_now - current_window_start_;
    
    double previous_window_overlap = max(0.0,1.0 - (time_elapsed.count()/window_size_.count()));
    
    double effective_count = previous_window_overlap*previous_window_count_ + current_window_count_;
    
    if (effective_count >= rate_limit_) {
        return false;
    } 
    
    current_window_count_++;
    
    return true;
}

/** === Program Logic === **/

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    
           
    return 0;
    
}
