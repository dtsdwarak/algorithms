class Solution {
    
    int bfs(vector<vector<char>> &grid, int i, int j) {
        
        int r = grid.size(), c = grid[0].size();
        
        if (i < 0 || i == r || j < 0 || j == c || grid[i][j] == '0')
            return 0;
        
        queue<pair<int, int>> q;
        q.push({i,j});
        
        while(!q.empty()) {
            
            pair<int, int> node = q.front();
            q.pop();
            
            i= node.first, j = node.second;
            
            if (i < 0 || i == r || j < 0 || j == c || grid[i][j] == '0')
                continue;
            
            grid[i][j] = '0';
            
            q.push({i-1, j});
            q.push({i+1, j});
            q.push({i, j-1});
            q.push({i, j+1});
        }
        
        return 1;
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int r = grid.size(), c = grid[0].size(), islands=0;
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++)
                islands += bfs(grid, i, j);
        }
        
        return islands;
        
    }
};
