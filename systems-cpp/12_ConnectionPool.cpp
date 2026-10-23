# include <bits/stdc++.h>

using namespace std;

class Connection
{

public:

    explicit Connection(int id) : id_(id) {}

    int id() const
    {
        return id_;
    }

private:

    int id_;
};

class ConnectionPool
{

private:

    queue<shared_ptr<Connection>> available_connections_;
    size_t max_connections_;
    bool shutdown_ = false;
    mutable mutex mutex_;
    condition_variable cv_;

public:

    explicit ConnectionPool(size_t max_connections): max_connections_(max_connections)
    {
        for (size_t i = 0; i < max_connections_;++i)
        {
            available_connections_.push(make_shared<Connection>(i));
        }
    }

    shared_ptr<Connection> acquire()
    {

        unique_lock<mutex> lock(mutex_);
        cv_.wait(lock, [this] { return shutdown_ || !available_connections_.empty();});

        if (shutdown_)
        {
            throw runtime_error( "pool shutdown" );
        }

        auto conn = available_connections_.front();
        available_connections_.pop();

        return conn;
    }

    void release(shared_ptr<Connection> connection)
    {
        {
            lock_guard<mutex> lock(mutex_);
            available_connections_.push(move(connection));
        }
        cv_.notify_one();
    }

    void shutdown()
    {
        {
            lock_guard<mutex> lock(mutex_);
            shutdown_ = true;
        }
        cv_.notify_all();
    }

    size_t available() const

    {
        lock_guard<mutex> lock(mutex_);
        return available_connections_.size();
    }

};



/** === Program Logic === **/

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    
           
    return 0;
    
}
