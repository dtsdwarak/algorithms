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

void dfs(vector<int> adj[], int V, int source) {

  vector<bool> visited(V, false);
  stack<int> s;
  
  s.push(source);
  
  while(!s.empty()) {
    
    int vertex = s.top();
    s.pop();
    
    cout<<"--"<<vertex;
    
    visited[vertex] = true;
    for (int i = 0; i<adj[vertex].size(); i++) {
        if (!visited[adj[vertex][i]])
          s.push(adj[vertex][i]);
    }
  }
  
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
    
    dfs(adj,V,2);
    
    return 0;
    
}
