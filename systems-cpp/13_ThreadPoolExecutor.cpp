# include <bits/stdc++.h>

using namespace std;

class Executor
{

public:

    virtual void execute(std::function<void()> task) = 0;
    virtual ~Executor() = default;

};

class ThreadPoolExecutor : public Executor
{

private:

    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> tasks_;

    std::mutex mutex_;
    std::condition_variable cv_;
    bool stopping_;

public:

    explicit ThreadPoolExecutor(size_t workers): stopping_(false)
    {
        for (size_t i = 0; i < workers;i++)
        {
            workers_.emplace_back(
                [this]
                {
                    worker_loop();
                }
            );
        }
    }

    
    ~ThreadPoolExecutor()
    {
        shutdown();
    }

    void execute(std::function<void()> task) override
    {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if (stopping_)
            {
                throw std::runtime_error( "executor stopped");
            }

            tasks_.push(std::move(task));
        }
        cv_.notify_one();
    }

    void shutdown()
    {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            stopping_ = true;
        }
        cv_.notify_all();

        for (auto& worker :  workers_)
        {
            if (worker.joinable())
            {
                worker.join();
            }
        }
    }

private:

    void worker_loop()
    {
        while (true)
        {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(mutex_);
                cv_.wait(lock,
                    [this]
                    {
                        return stopping_ || !tasks_.empty();
                    }
                );

                if (stopping_ && tasks_.empty())
                {
                    return;
                }

                task = std::move(tasks_.front());
                tasks_.pop();
            }

            try
            {
                task();
            }
            catch (...)
            {
                /*
                 * Production systems
                 * log and continue.
                 */
            }
        }
    }
};


/** === Program Logic === **/

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    
           
    return 0;
    
}
