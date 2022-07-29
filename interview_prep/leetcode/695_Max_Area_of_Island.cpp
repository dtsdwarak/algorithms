class Solution {
    
    void getArea(vector<vector<int>> &grid, int i, int j, int &area) {
        
        int r = grid.size(), c = grid[0].size();
        
        if (i < 0 || i == r || j < 0 || j == c || grid[i][j] == 0)
            return;
        
        area++;
        grid[i][j] = 0;
        
        getArea(grid, i-1, j, area);
        getArea(grid, i+1, j, area);
        getArea(grid, i, j-1, area);
        getArea(grid, i, j+1, area);
        
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int r = grid.size(), c = grid[0].size(), area, maxArea = INT_MIN;
        
        for(int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                area = 0;
                getArea(grid, i, j, area);
                maxArea = max(area, maxArea);
            }
        }
        
        return maxArea;
        
    }
};
