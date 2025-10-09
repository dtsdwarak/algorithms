#include <atomic>
#include <chrono>

class TokenBucket {
public:
    TokenBucket(double rate_per_sec, double burst)
        : rate_(rate_per_sec), capacity_(burst), tokens_(burst),
          last_ns_(nowNs()) {}

    bool allow() {
        auto t = nowNs();
        refill(t);
        double cur = tokens_.load(std::memory_order_relaxed);
        while (cur >= 1.0) {
            if (tokens_.compare_exchange_weak(cur, cur - 1.0,
                    std::memory_order_acq_rel, std::memory_order_relaxed))
                return true;
        }
        return false;
    }

private:
    static uint64_t nowNs() {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(
                   std::chrono::steady_clock::now().time_since_epoch()).count();
    }

    void refill(uint64_t t) {
        uint64_t prev = last_ns_.load(std::memory_order_relaxed);
        double add = 0.0;
        for (;;) {
            uint64_t now = last_ns_.load(std::memory_order_relaxed);
            prev = now;
            uint64_t dt = t - now;
            add = (double)dt * rate_ / 1e9;
            if (add <= 0) return;
            if (last_ns_.compare_exchange_weak(now, t,
                    std::memory_order_acq_rel, std::memory_order_relaxed)) break;
        }
        double cur = tokens_.load(std::memory_order_relaxed);
        double nxt;
        do {
            nxt = std::min(capacity_, cur + add);
        } while (!tokens_.compare_exchange_weak(cur, nxt,
                 std::memory_order_acq_rel, std::memory_order_relaxed));
    }

    const double rate_;
    const double capacity_;
    std::atomic<double> tokens_;
    std::atomic<uint64_t> last_ns_;
};

