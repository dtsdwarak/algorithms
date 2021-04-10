/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

#define pval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define MAX_VAL INT_MAX

using namespace std;

typedef long long ll;


void floydWarshall(vector<vector<int>> adjList) {

    for(int i=0;i<adjList.size();i++) {
    
        for(int j=0;j<adjList.size()-1;j++) {
            for(int k=1;k<adjList.size();k++) {
                if (adjList[j][i] != MAX_VAL && adjList[i][k] != MAX_VAL)
                  adjList[j][k] = min(adjList[j][i] + adjList[i][k], adjList[j][k]);
            }
        }
    }
    
    for(int i = 0; i<adjList.size();i++){
      for(int j=0;j<adjList.size();j++) {
          cout<<adjList[i][j]<<"--";
      }
      cout<<"\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> adjList { 
                                  {0,       5,       MAX_VAL, 10     },
                                  {MAX_VAL, 0,       3,       MAX_VAL},
                                  {MAX_VAL, MAX_VAL, 0,       1      },
                                  {MAX_VAL, MAX_VAL, MAX_VAL, 0      }
                                };
    
    floydWarshall(adjList);
    
    return 0;
}
