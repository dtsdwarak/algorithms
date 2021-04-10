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

void topologicalSort(vector<int> adj[], vector<bool> &visited, int vertex, stack<int> &s) {
  
  for(int i=0;i<adj[vertex].size();i++) {
      
      if (!visited[adj[vertex][i]])
        topologicalSort(adj, visited, adj[vertex][i], s);
  }
  
  if (!visited[vertex]) {
    s.push(vertex);
    visited[vertex] = true;
  }
  
}

void topologicalSortComplete(vector<int> adj[], int V) {

    vector<bool> visited(V, false);
    stack<int> s;
    
    for(int i=0;i<V;i++) {
      if (!visited[i])
        topologicalSort(adj, visited, i, s);
    }
    
    while(!s.empty()) {
        
        cout<<s.top()<<"--";
        s.pop();
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V=6;
    vector<int> adj[V];
    
    addEdge(adj, 5, 2);
    addEdge(adj, 5, 0);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    
    topologicalSortComplete(adj, V);
    
}
