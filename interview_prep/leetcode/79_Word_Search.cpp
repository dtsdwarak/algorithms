class Solution {

private:

    bool dfs(vector<vector<char>> &board, 
            vector<vector<bool>> &visited, 
            int& m, 
            int& n, 
            int i,
            int j, 
            string& word, 
            string selected) {

        if (word == selected)
            return true;
        
        if (i<0 || j <0 || i > m-1 || j > n-1)
            return false;

        if (selected.length() > word.length())
            return false;

        if (board[i][j] != word[selected.length()])
            return false;

        if (visited[i][j])
            return false;
        
        visited[i][j] = true;
        
        bool found =  dfs (board,visited,m,n,i+1,j,word,selected + board[i][j]) ||
                      dfs (board,visited,m,n,i-1,j,word,selected + board[i][j]) || 
                      dfs (board,visited,m,n,i,j+1,word,selected + board[i][j]) || 
                      dfs (board,visited,m,n,i,j-1,word,selected + board[i][j]);

        visited[i][j] = false;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (dfs(board, visited, m, n, i, j, word, ""))
                    return true;
            }
        }
        return false;
    }
};
