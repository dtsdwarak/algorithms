# include <bits/stdc++.h>

using namespace std;

/*
 * Multiple readers can read together
 * But w.r.t Writer, only one can be active at a give point
 * And when another writer OR readers are active, the writer in question waits.
 */ 
class RWLock {

private:

        mutex mutex_;
        condition_variable reader_cv_;
        condition_variable writer_cv_;
        int active_readers_ = 0;
        int waiting_writers_ = 0;
        bool writer_active_ = false;
    
public:

    void lock_read();
    void unlock_read();
    void lock_write();
    void unlock_write();
};

void RWLock::lock_read() {

    unique_lock<mutex> lock(mutex_);
    
    // Do not provide read lock until 
    // 1. No writer is active
    // 2. No writer is waiting
    reader_cv_.wait(lock, [this] { return !writer_active_ && waiting_writers_ = 0; });
    
    ++active_readers_;
}

void RWLock::unlock_read() {
    
    unique_lock<mutex> lock(mutex_);
    
    --active_readers_;
    
    // Last Reader wakes writer
    if (active_readers_ == 0) {
        writer_cv_.notify_one();
    }
    
}

void RWLock::lock_write() {

    unique_lock<mutex> lock(mutex_);
    waiting_writers_++;
    
    // Wait until 
    // 1. NO active writer
    // 2. NO active reader
    writer_cv_.wait(lock, [this] { return !writer_active_ && active_readers_ == 0;});
    
    waiting_writers_--;
    writer_active_ = true;    
}

void RWLock::unlock_write() {

    unique_lock<mutex> lock(mutex_);
    
    writer_active_ = false;

    // If more writers are waiting
    // awake them first.
    if (waiting_writers_ > 0) {
        writer_cv_.notify_one();
    } else {
       // If not, start all readers
       reader_cv_.notify_all(); 
    }
    
}

/** === Program Logic === **/

    
unordered_map<int, int> cache_;
RWLock lock_;

void reader() {

    lock_.lock_read();
    auto it = cache_.find(2);
    lock.unlock_read();
    
}

void writer() {

    lock_.lock_write();
    cache_[3] = 5;
    lock.unlock_write();
    
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
    
}
