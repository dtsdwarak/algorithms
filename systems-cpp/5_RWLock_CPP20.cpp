#include <bits/stdc++.h>

class Database
{

private:
    int value_ = 0;
    std::shared_mutex mutex_;

public:

    int read(int reader_id)
    {
        std::shared_lock lock(mutex_);

        std::cout << "Reader "<< reader_id<< " reading value "<< value_<< std::endl;
        std::this_thread::sleep_for(
            std::chrono::seconds(2)
        );

        return value_;
    }

    

    void write(int new_value, int writer_id)
    {
        std::unique_lock lock(mutex_);

        std::cout<< "Writer " << writer_id<< " writing value " << new_value<< std::endl;

        std::this_thread::sleep_for(
            std::chrono::seconds(3)
        );

        value_ = new_value;
    }
};

int main()
{
    Database db;

    std::vector<std::thread> threads;

    threads.emplace_back(
        [&]
        {
            db.read(1);
        }
    );

    threads.emplace_back(
        [&]
        {
            db.read(2);
        }
    );

    threads.emplace_back(
        [&]
        {
            db.read(3);
        }
    );

    std::this_thread::sleep_for(
        std::chrono::milliseconds(100)
    );

    threads.emplace_back(
        [&]
        {
            db.write(42, 1);
        }
    );

    threads.emplace_back(
        [&]
        {
            db.read(4);
        }
    );

    for (auto& thread : threads)
    {
        thread.join();
    }
}
