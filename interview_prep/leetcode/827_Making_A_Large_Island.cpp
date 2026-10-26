/*

### The Core Challenge & Brute Force Trap

* **The Problem:** You can change **at most one** `0` to a `1`. You want to find the maximum possible island size you can create.
* **The Naive Approach:** For every single `0` in the grid, temporarily flip it to a `1`, run a full DFS/BFS to compute the resulting island size, and flip it back.
* **Why it fails / is too slow:** If the grid is $N \times N$, doing a full traversal for every zero results in an $\mathcal{O}(N^4)$ time complexity. For $N = 50$, that’s millions of redundant traversals. We need a way to evaluate every `0` in **$\mathcal{O}(1)$ time**.

---

### The Optimal $\mathcal{O}(N^2)$ Strategy

Instead of recalculating islands from scratch for every zero, we can solve this in two clean passes:

1. **Pass 1: Island Labeling & Sizing (DFS)**
* Traverse the grid and find every distinct island of `1`s.
* Assign each island a **unique ID** (starting from `2`, since `0` and `1` are already used in the grid) and overwrite the `1`s with that ID.
* Simultaneously, store the size of each island in a hash map: `island_id -> size`.
* Keep track of the largest island found so far (in case the grid has no zeros or we choose not to flip anything).


2. **Pass 2: Evaluating Every `0**`
* Loop through every cell that is currently a `0`.
* Check its 4 neighbors (up, down, left, right).
* If a neighbor contains an island ID (i.e., `grid[ni][nj] > 1`), look up its size in our hash map.
* **Crucial Detail:** Use a `std::unordered_set` to collect neighbor IDs. This prevents double-counting if two or more sides of a `0` touch the *same* island.
* Sum up the unique neighbor island sizes plus `1` (for the flipped `0` itself), and track the global maximum.


---

### Complexity Analysis

* **Time Complexity:** $\mathcal{O}(N^2)$
* Pass 1 (DFS labeling) visits every cell at most once: $\mathcal{O}(N^2)$.
* Pass 2 (Checking every zero and its 4 neighbors) executes in constant time per cell: $\mathcal{O}(N^2)$.


* **Space Complexity:** $\mathcal{O}(N^2)$ for the DFS recursion stack (in the worst-case grid of all ones) and the `islandSize` hash map tracking component sizes.
*/

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int islandId = 2; // Start IDs from 2 to avoid confusion with 0 and 1
        unordered_map<int, int> islandSize;
        int maxIsland = 0;

        // Pass 1: Label each island with a unique ID and compute its size
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, islandId);
                    islandSize[islandId] = size;
                    maxIsland = max(maxIsland, size); // Track largest existing island
                    islandId++;
                }
            }
        }

        // Pass 2: Evaluate turning every 0 into 1
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighboringIslands;
                    int currentSize = 1; // The flipped zero itself

                    // Check all 4 neighbors
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dr[k], nj = j + dc[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1) {
                            neighboringIslands.insert(grid[ni][nj]);
                        }
                    }

                    // Sum up unique neighboring island sizes
                    for (int id : neighboringIslands) {
                        currentSize += islandSize[id];
                    }

                    maxIsland = max(maxIsland, currentSize);
                }
            }
        }

        return maxIsland;
    }

private:
    int dfs(vector<vector<int>>& grid, int r, int c, int id) {
        int n = grid.size();
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1) {
            return 0;
        }
        grid[r][c] = id; // Mark cell with unique island ID
        int size = 1;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        for (int k = 0; k < 4; ++k) {
            size += dfs(grid, r + dr[k], c + dc[k], id);
        }
        return size;
    }
};
