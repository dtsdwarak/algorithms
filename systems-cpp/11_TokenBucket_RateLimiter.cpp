# include <bits/stdc++.h>

using namespace std;

class TokenBucket {
    
private:

    const double capacity_;
    const double refill_rate_;
    double available_tokens_;
    chrono::steady_clock::time_point last_refill_time_;
    mutable mutex mutex_;
    
    void refill_tokens();
    
public:

    TokenBucket(double capacity, double refill_rate):capacity_(capacity),refill_rate_(refill_rate),available_tokens_(capacity),last_refill_time_(chrono::steady_clock::now()) {}
    
    TokenBucket(const TokenBucket&)=delete;
    TokenBucket& operator=(const TokenBucket&)=delete;
    
    TokenBucket(TokenBucket&&)=delete;
    TokenBucket& operator=(TokenBucket&&)=delete;
    
    bool allow();
    
};

void TokenBucket::refill_tokens() {
    
    chrono::steady_clock::time_point time_now = chrono::steady_clock::now();
    chrono::duration<double> elapsed_time = time_now - last_refill_time_;
    
    double new_tokens = elapsed_time.count() * refill_rate_;
    
    available_tokens_ = min(capacity_, available_tokens_ + new_tokens);
    
    last_refill_time_ = time_now;
}


bool TokenBucket::allow() {

    lock_guard<mutex> lock(mutex_);
    refill_tokens();
    
    if (available_tokens_ < 1.0) {
        return false;
    }
    
    available_tokens_--;
    return true;
}



/** === Program Logic === **/

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    TokenBucket tb(10,5);
    
    for(size_t i=0;i<10;i++) {
        
        cout<<"Request "<<i<<" "<<(tb.allow() ? "allowed" : "rejected")<<endl;
    }
        
    return 0;
    
}
