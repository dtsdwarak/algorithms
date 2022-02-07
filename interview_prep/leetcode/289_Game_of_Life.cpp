class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int m = board.size(), n = board.size() > 0 ? board[0].size() : 0;
        
        for(int i=0; i<m; i++) {
            
            for(int j=0; j<n; j++) {
                
                int lives = getLiveNeighbours(board, i, j, m, n);
                
                if (board[i][j] == 1 && (lives == 2 || lives ==3))
                    board[i][j] = 3;
                else if (board[i][j] == 0 && lives == 3)
                    board[i][j] = 2;
                
            }
            
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++)
                board[i][j] >>= 1;
        }
        
        
    }
    
    
    int getLiveNeighbours(vector<vector<int>>& board, int &i, int &j, int &m, int &n) {
        
        int lives = 0;
        
        for(int p = max(0, i-1); p < min(i+2, m); p++) {
            for(int q = max(0, j-1); q < min(j+2, n); q++) {
                
                lives += board[p][q] & 1;
                
            }
        }
        
        lives -= board[i][j] & 1;
        return lives;
        
    }
    
};
