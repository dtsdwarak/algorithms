class Solution {
    
    pair<int, int> fetchIndices(int no, int n) {
        return make_pair(no/n, no % n);
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m*n-1, mid;
        
        while(low <= high) {
            
            
            int mid = low + (high - low)/2;
            pair<int, int> indices = fetchIndices(mid, n);
            
            if (matrix[indices.first][indices.second] == target)
                return true;
            
            else if (matrix[indices.first][indices.second] < target)
                low = mid +1;
            else
                high = mid-1;
        }
        
        return false;
        
    }
};

