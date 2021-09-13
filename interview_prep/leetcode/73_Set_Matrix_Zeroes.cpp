class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        set<int> setOfRowsTobeMadeZero;
        set<int> setOfColumnsTobeMadeZero;
        
        for(int i=0; i<matrix.size();i++) {
            for(int j=0; j<matrix[0].size();j++) {
                if (matrix[i][j] == 0) {
                    setOfRowsTobeMadeZero.insert(i);
                    setOfColumnsTobeMadeZero.insert(j);
                }
            }
        }
        
        for(int i=0; i<matrix.size();i++) {
            for(int j=0; j<matrix[0].size();j++) {
                if (setOfRowsTobeMadeZero.count(i) || setOfColumnsTobeMadeZero.count(j))
                    matrix[i][j] = 0;
            }
        }
        
    }
};
