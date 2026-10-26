class Solution {


public:

    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> hasBox(n, false);
        vector<bool> hasKey(n, false);
        vector<bool> visited(n, false);
        queue<int> q;

        int totalCandies = 0;

        // 1. Initialize with starting boxes
        for (int box : initialBoxes) {
            hasBox[box] = true;
            // If the starting box is open, we can process it immediately
            if (status[box] == 1) {
                visited[box] = true;
                q.push(box);
            }
        }

        // 2. BFS State Machine Execution
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Collect candies from the opened box
            totalCandies += candies[curr];

            // Process all keys found inside this box
            for (int key : keys[curr]) {
                hasKey[key] = true;
                // If we already possess this box, couldn't open it earlier, and haven't visited it yet
                if (hasBox[key] && !visited[key]) {
                    visited[key] = true;
                    q.push(key);
                }
            }

            // Process all sub-boxes found inside this box
            for (int nextBox : containedBoxes[curr]) {
                hasBox[nextBox] = true;
                // If the box is openable (status == 1 or we have its key) and not yet visited
                if (!visited[nextBox] && (status[nextBox] == 1 || hasKey[nextBox])) {
                    visited[nextBox] = true;
                    q.push(nextBox);
                }
            }
        }

        return totalCandies;
    }
};
