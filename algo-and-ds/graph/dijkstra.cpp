/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

#define pval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using namespace std;

typedef long long ll;
typedef pair<int,int> iPair;

void addEdge(vector<iPair> adj[], int u, int v, int weight) {
    
    adj[u].push_back(make_pair(v,weight));
    adj[v].push_back(make_pair(u,weight));
}


void shortestPath(vector<iPair> adj[], int V, int source) {

    // We are creating a min-heap of all edges in the graph.
    priority_queue< iPair, vector<iPair>, greater<iPair > > pq;
    
    // Declare all distances between source and all vertices as INT_MAX except "source"
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;
    
    pq.push(make_pair(0, source));
    
    while (!pq.empty()) {
      
      int u = pq.top().second;
      pq.pop();
      
      for(auto i : adj[u]) {
          
          int v = i.first;
          int weight = i.second;
          
          if (dist[v] > dist[u] + weight) {
              dist[v] = dist[u] + weight;
              pq.push(make_pair(dist[u]+weight,v));
          }
      }
      
    }
    
    
    for(int i = 0 ; i< V; i++)
      cout<<"Distance of "<<i<<" from source = "<<dist[i]<<"\n";
    
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V = 9;
    vector<iPair> adj[V];
    
    
        // making above shown graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
  
    shortestPath(adj, V, 0);    
    
}
