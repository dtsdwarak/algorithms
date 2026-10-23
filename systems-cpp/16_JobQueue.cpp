/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

using namespace std;

/** 
 * 1. Implement the Job struct that is composed of two integers, the id (name = id) and 
 * the job duration in milliseconds (name = duration). 
 * 
 * It also has a member function that is called run() and the signature is the following: bool run(std::stop_token st) const noexcept; It will return true if it could sleep for this time, false otherwise (in case of a termination)
 * The run() function will be responsible for sleeping for 
 * `duration`  while being able to react to cancellation that may come via the stop_token.
 **/

struct Job {
    int id;
    int duration; // milliseconds

    // Sleeps for `duration` ms, but wakes up early if a stop is requested.
    // Returns true  -> slept the full duration (completed normally)
    // Returns false -> woke up early because of a stop request (or an error)
    bool run(std::stop_token st) const noexcept {
        try {
            std::mutex mtx;
            std::condition_variable_any cv;
            std::unique_lock<std::mutex> lock(mtx);

            // wait_for(lock, stop_token, rel_time, pred) returns when:
            //   - pred() becomes true, or
            //   - rel_time elapses, or
            //   - a stop is requested on `st`
            // Since nothing else ever notifies this cv, the only ways to
            // return are "timeout elapsed" or "stop requested".
            cv.wait_for(lock, st, std::chrono::milliseconds(duration),
                        [] { return false; });

            // If we get here because of a stop request, stop_requested()
            // will be true; if the full duration elapsed normally, it
            // will be false.
            return !st.stop_requested();
        } catch (...) {
            // run() is noexcept, so never let an exception escape.
            return false;
        }
    }
};

/**
 * 2. Implement a Queue that will be used to queue jobs and have them executed by a WorkerPool. 
 * Implement the function void push(Job j)
 * Implement the function bool pop(Job & out, std::stop_token st) 
 *   it will return true if an element could have been popped, 
 *   false otherwise (Ignore the stop_token in the body of this function ;))
 **/

class Queue {
public:
    // Adds a job to the back of the queue and wakes up one waiting consumer.
    void push(Job j) {
        {
            std::lock_guard<std::mutex> lock(mtx_);
            jobs_.push(std::move(j));
        }
        cv_.notify_one();
    }

    // Blocks until either a job is available (returns true, job in `out`)
    // or a stop is requested on `st` (returns false).
    bool pop(Job& out, std::stop_token st) {
        std::unique_lock<std::mutex> lock(mtx_);

        // wait_for/wait with a stop_token: wakes up when the predicate
        // becomes true OR when a stop is requested. We just pass st along
        // and let the cv machinery deal with cancellation for us.
        bool has_job = cv_.wait(lock, st, [this] { return !jobs_.empty(); });

        if (!has_job) {
            // Woke up because of a stop request, queue still empty.
            return false;
        }

        out = std::move(jobs_.front());
        jobs_.pop();
        return true;
    }

private:
    std::mutex mtx_;
    std::condition_variable_any cv_;
    std::queue<Job> jobs_;
};
