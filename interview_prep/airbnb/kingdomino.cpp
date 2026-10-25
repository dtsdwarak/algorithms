# include <bits/stdc++.h>

using namespace std;

pair<int, int> dfs(vector<vector<string>>& board, vector<vector<bool>>& visited, char currentTile, int i, int j, int& m, int& n) {

    if (i < 0 || j <0 || i > m-1 || j > n-1 || visited[i][j] || board[i][j][0] != currentTile)
        return {0, 0};

    visited[i][j] = true;

    int area = 1;
    int crowns = stoi(board[i][j].substr(1));

    for (auto item : {pair<int,int>{0,1}, {0,-1}, {1,0}, {-1,0}}) {
        int x = item.first, y = item.second;
        pair<int, int> areaCrownPair = dfs(board, visited, currentTile, i+x, j+y, m, n);
        area += areaCrownPair.first;
        crowns += areaCrownPair.second;
    }

    return {area, crowns};
}

int main() {


    vector<vector<string>> board {
    {"L0","W1","W1","W0","F2"},
    {"W0","W0","T0","T0","T0"},
    {"W0","W1","T0","R2","R1"},
    {"L0","K0","L1","L0","L0"},
    {"R0","C2","C0","L1","T0"}
    };

    int m = board.size();
    int n = board[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    pair<int, int> tileCountAndCrowns;
    int totalScore = 0;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if (!visited[i][j]) {
                tileCountAndCrowns = dfs(board, visited, board[i][j][0], i, j, m, n);
                totalScore += tileCountAndCrowns.first * tileCountAndCrowns.second;
            }
        }
    }

    cout<<totalScore;

}
