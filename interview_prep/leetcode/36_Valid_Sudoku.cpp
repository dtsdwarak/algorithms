class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_set<int> > rows(9, unordered_set<int>());
        vector<unordered_set<int> > columns(9, unordered_set<int>());
        vector<unordered_set<int> > boxes(9, unordered_set<int>());
        
        for(int row=0; row<9; row++) {
            for(int col=0; col<9; col++) {
                
                if (board[row][col] == '.')
                    continue;
                
                int currentValue = board[row][col] - 48;
                
                if (currentValue < 1 || currentValue > 9)
                    return false;
                
                // Check for rows
                if (rows[row].find(currentValue) != rows[row].end())
                    return false;
                rows[row].insert(currentValue);
                    
                // Check for columns
                if (columns[col].find(currentValue) != columns[col].end())
                    return false;
                columns[col].insert(currentValue);
                
                // Check for boxes
                int box_i = row/3;
                int box_j = col/3;
                int boxIterationValue = 3 * box_i + box_j;
                
                if (boxes[boxIterationValue].find(currentValue) != boxes[boxIterationValue].end())
                    return false;
                boxes[boxIterationValue].insert(currentValue);
            }
        }
        
        return true;
    }
};
