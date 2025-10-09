#include <fstream>

template <typename Key, typename Value>
class PersistentCache : public ThreadSafeCache<Key, Value> {
public:
    explicit PersistentCache(std::string filename) : file_(std::move(filename)) {}

    void put(const Key& key, const Value& value) {
        ThreadSafeCache<Key, Value>::put(key, value);
        appendToLog(key, value);
    }

private:
    void appendToLog(const Key& key, const Value& value) {
        std::ofstream out(file_, std::ios::app);
        out << key << " " << value << "\n";
    }

    std::string file_;
};

