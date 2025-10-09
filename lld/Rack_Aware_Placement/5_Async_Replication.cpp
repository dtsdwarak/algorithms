#include <random>
#include <iostream>

bool simulateNetworkCopy(const std::string& srcNode, const std::string& dstNode, const std::string& key) {
    // simulate variable network cost & failure
    std::this_thread::sleep_for(std::chrono::milliseconds(50 + (rand() % 200)));
    // simulate random failure
    if ((rand() % 10) < 2) return false;
    std::cout << "Copied " << key << " from " << srcNode << " to " << dstNode << "\n";
    return true;
}

void replicateObjectTask(const std::string& key, const std::string& src, const std::string& dst, int maxRetries = 3) {
    for (int attempt = 1; attempt <= maxRetries; ++attempt) {
        if (simulateNetworkCopy(src, dst, key)) {
            // update metadata store to add dst to replica list (omitted)
            return;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100 * attempt)); // backoff
    }
    // report failure to metadata/alerting
}

