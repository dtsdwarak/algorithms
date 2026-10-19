class Solution {

    void ignoreRegions(vector<vector<char>> &board, int& m, int& n, int i, int j) {

        if (i < 0 || j < 0 || i == m || j == n || board[i][j] == 'X' || board[i][j] == 'Y')
            return;
        
        board[i][j] = 'Y';

        ignoreRegions(board, m, n, i+1, j);
        ignoreRegions(board, m, n, i-1, j);
        ignoreRegions(board, m, n, i, j+1);
        ignoreRegions(board, m, n, i, j-1);

    } 

    void captureRegion(vector<vector<char>> &board, int& m, int& n, int i, int j) {

        if (i < 1 || j < 1 || i == m-1 || j == n-1 || board[i][j] == 'X' || board[i][j] == 'Y')
            return;
        
        board[i][j] = 'X';

        captureRegion(board, m, n, i+1, j);
        captureRegion(board, m, n, i-1, j);
        captureRegion(board, m, n, i, j+1);
        captureRegion(board, m, n, i, j-1);

    } 

public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size(); // rows
        int n = board[0].size(); //cols

        
        for(int i=0; i<m; i++) {
            for(int j : {0, n-1}) {
                ignoreRegions(board, m, n, i, j);
            }
        }

        for(int j=0; j<n; j++) {
            for(int i : {0, m-1}) {
                ignoreRegions(board, m, n, i, j);
            }
        }

        // Capture Region
        for(int i=1; i<m-1; i++) {
            for(int j=1; j<n-1; j++) {
                captureRegion(board, m, n, i, j);
            }
        }

        // Set ignored regions back to "O"
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }

    }
};
