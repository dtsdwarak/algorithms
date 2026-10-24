class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        // Base conditions

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        if (grid.size() == 1)
            return 1;
        

        // -----------

        queue<pair<int, int>> q;
        q.push({0,0});
        grid[0][0] = 1; 

        int currentLevelLength = 0;

        vector<pair<int, int>> directions = {
            {-1, -1},
            {-1, 1},
            {-1, 0},
            {0, 1},
            {0, -1},
            {1, -1},
            {1, 0},
            {1, 1},
        };

        while(!q.empty()) {

            int size = q.size();


            // For BFS, drain the entire level first so you can increase the 
            // currentLevelLength before proceeding ahead.
            for(int k=0; k<size; k++) {
                pair<int, int> p = q.front();
                q.pop();

                if (p.first == n-1 && p.second == n-1)
                return currentLevelLength+1;

                int i = p.first, j=p.second;

                for(const auto& direction: directions) {
                    int new_i = i + direction.first;
                    int new_j = j + direction.second;

                    if (new_i < 0 || new_j < 0 || new_i > n-1 || new_j > n-1 || grid[new_i][new_j] == 1)
                        continue;

                    grid[new_i][new_j] = 1;
                    q.push({new_i,new_j});
                }
            }
            currentLevelLength++;
        }
        return -1;
    }
};
