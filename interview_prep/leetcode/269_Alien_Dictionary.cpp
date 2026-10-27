class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        // 1. Initialize all unique characters with 0 in-degree
        for (const string& word : words) {
            for (char c : word) {
                inDegree[c] = 0;
            }
        }

        // 2. Build the adjacency list and compute in-degrees by comparing adjacent words
        for (size_t i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i];
            string w2 = words[i + 1];
            
            size_t len = min(w1.length(), w2.length());
            bool foundDifference = false;

            for (size_t j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    char parent = w1[j];
                    char child = w2[j];

                    // Add directed edge if not already recorded
                    if (adj[parent].find(child) == adj[parent].end()) {
                        adj[parent].insert(child);
                        inDegree[child]++;
                    }
                    foundDifference = true;
                    break;
                }
            }

            // Edge Case: Invalid prefix rule (e.g., ["abc", "ab"])
            if (!foundDifference && w1.length() > w2.length()) {
                return "";
            }
        }

        // 3. Kahn's Algorithm: Push all nodes with 0 in-degree into queue
        queue<char> q;
        for (const auto& pair : inDegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }

        string result = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            for (char neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 4. Cycle Check: If result length doesn't match total unique characters, a cycle exists
        if (result.length() != inDegree.size()) {
            return "";
        }

        return result;
    }
};
