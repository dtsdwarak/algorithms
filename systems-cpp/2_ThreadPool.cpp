# include <bits/stdc++.h>

using namespace std;

typedef function<void()> Job;

class ThreadPool {
    
private:

    vector<thread> workers_;
    queue<Job> jobs_;
    mutex mutex_;
    condition_variable cv_;
    bool shutdown_;
    
    void worker_loop() {
        while(true) {
            Job job;
            {
                unique_lock<mutex> lock(mutex_);
                cv_.wait(lock, [this] {return shutdown_ || !jobs_.empty(); });
                if (shutdown_ && jobs_.empty()) {
                    cout<<"Nothing left to process";
                    return;
                }
                job = move(jobs_.front());
                jobs_.pop();
            }
            job();
        }
    }
  
public:
  
  explicit ThreadPool(size_t num_threads) {
  
    for (size_t i=0; i<num_threads; i++) {
        workers_.emplace_back([this] {worker_loop();});
    }
      
  }
  
  // Disable copy constructor
  ThreadPool(const ThreadPool&) = delete;
  // Disbale copy assignment operator
  ThreadPool& operator=(const ThreadPool&) = delete;
    
    
  void submit(Job job) {
    {
        lock_guard<mutex> lock(mutex_);
        
        if (shutdown_) {
            throw runtime_error("Shutdown initiated. No further jobs can be queued");
        }
        jobs_.push(move(job));
    }
    cv_.notify_one();   
  }
  
  
  void shutdown() {
    {
        lock_guard<mutex> lock(mutex_);
        shutdown_ = true;
    }
    cv_.notify_all();
    for (auto& worker: workers_) {
        if (worker.joinable()) {
            worker.join();
        }  
    }
      
  }
  // Destructor
  ~ThreadPool() { shutdown(); };
};

/** === Program Logic === **/

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ThreadPool pool(4);
    
    for(size_t i=0; i<10; i++) {
            
        pool.submit(
            [i] 
            {
                cout<<"Task "<<i<<" executed by "<<this_thread::get_id()<<endl;
            }
        );
    }
    
    pool.shutdown();
    
    return 0;
    
}
