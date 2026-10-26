/*

**LeetCode 773: Sliding Puzzle** is a classic shortest-path problem on an unweighted state graph. It looks like a grid game, but structurally, it’s identical to finding the shortest path in a graph where every unique board configuration is a node, and swapping the empty space (`0`) with an adjacent tile represents an edge transition.

---

### Core Strategy & Intuition

1. **Flattening the Board (State Representation):**
A $2 \times 3$ board can be flattened into a single 6-character string. For example:

$$\begin{bmatrix} 1 & 2 & 3 \\ 4 & 0 & 5 \end{bmatrix} \implies \text{"123405"}$$

This allows us to easily use strings as keys in a hash set (`std::unordered_set`) to track visited states and prevent infinite loops.
2. **Breadth-First Search (BFS):**
Because we want the **least number of moves** (shortest path) to reach the target state (`"123405"`), **BFS** is the optimal choice. Each level in our BFS queue represents one move away from the previous state.
3. **Predefined Adjacency Map (The Grid Shortcut):**
Instead of writing complex 2D row/column boundary checks for up, down, left, and right movements, we can map the 6 indices of a flattened $2 \times 3$ grid to their valid neighbor indices:
* Index `0` can swap with: `1, 3`
* Index `1` can swap with: `0, 2, 4`
* Index `2` can swap with: `1, 5`
* Index `3` can swap with: `0, 4`
* Index `4` can swap with: `1, 3, 5`
* Index `5` can swap with: `2, 4`


---

### Complexity Analysis

* **Time Complexity:** $\mathcal{O}(V + E)$, where $V$ is the total number of unique valid board permutations. For a $2 \times 3$ sliding puzzle, there are $6! = 720$ possible board states. Thus, the BFS explores at most 720 states, executing in negligible time (well under 1ms).
* **Space Complexity:** $\mathcal{O}(V)$ to store the visited states in the hash set and the BFS queue, capped at 720 entries.

*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // 1. Convert 2D board to a 6-character string
        string start = "";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                start += to_string(board[i][j]);
            }
        }

        string target = "123450";
        if (start == target) return 0;

        // 2. Predefined valid swap indices for a 2x3 grid flattened to 0..5
        vector<vector<int>> neighbors = {
            {1, 3},       // Index 0
            {0, 2, 4},    // Index 1
            {1, 5},       // Index 2
            {0, 4},       // Index 3
            {1, 3, 5},    // Index 4
            {2, 4}        // Index 5
        };

        // 3. BFS setup
        queue<string> q;
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                // Check if we reached the solved state
                if (curr == target) return steps;

                // Find the position of '0'
                int zero_idx = curr.find('0');

                // Try swapping '0' with all valid adjacent positions
                for (int next_idx : neighbors[zero_idx]) {
                    string next_state = curr;
                    swap(next_state[zero_idx], next_state[next_idx]);

                    // If we haven't visited this configuration yet, push it to queue
                    if (visited.find(next_state) == visited.end()) {
                        visited.insert(next_state);
                        q.push(next_state);
                    }
                }
            }
            steps++;
        }

        return -1; // If target is unreachable
    }
};
