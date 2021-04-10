/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

#define pval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using namespace std;

typedef long long ll;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void dfs(vector<int> adj[], vector<bool> &visited, int source) {
  
  visited[source] = true;
  
  cout<<"--"<<source;
  
  for(int i=0;i<adj[source].size();i++) {
      
      if (!visited[adj[source][i]])
          dfs(adj,visited,adj[source][i]);
  }
  
}

void dfsComplete(vector<int> adj[], int V, int source) {

  vector<bool> visited(V, false);
  
  dfs(adj,visited,source);
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V = 10;
    vector<int> adj[V];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 9);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 9, 3);
    
    dfsComplete(adj,V,2);
    
    return 0;
}
