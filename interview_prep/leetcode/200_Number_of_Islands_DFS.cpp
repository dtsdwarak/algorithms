class Solution {
    
    int dfs(vector<vector<char>> &grid, int i, int j) {
        
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == '0')
            return 0;
        
        grid[i][j] = '0';
        
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        
        return 1;
        
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int r = grid.size(), c = grid[0].size(), islands = 0;
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++)
                islands += dfs(grid, i, j);
        }
        
        return islands;
    }
};
