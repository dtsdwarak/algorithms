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

void bfs(vector<int> adj[], vector<bool> &visited, int source) {
    
    visited[source] = true;
    
    queue<int> q;
    q.push(source);
    
    
    while(!q.empty()) {
      
      int vertex = q.front();
      q.pop();

      cout<<"--"<<vertex;

      for(int i=0; i<adj[vertex].size(); i++) {
          if (!visited[adj[vertex][i]]) {
              visited[adj[vertex][i]] = true;
              q.push(adj[vertex][i]);
          }
      }
    }
    
}

void bfsComplete(vector<int> adj[], int V, int source) {
    
    vector<bool> visited(V, false);
    bfs(adj,visited,source);
    
    for(int i=0; i<visited.size(); i++) {
        if (!visited[i])
          bfs(adj,visited,i);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V=5;
    vector<int> adj[V];
    
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    
    bfsComplete(adj,V,0);
    
    return 0;
}
