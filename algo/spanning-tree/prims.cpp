/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

#define pval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using namespace std;

typedef long long ll;
typedef pair<int, int> iPair;
typedef pair<int, pair<int, int> > iiPair;

/*
 * pair.first - adjacent vertex
 * pair.second - edge weight
 */
void addEdge(vector<iPair> adj[], int u, int v, int weight) {
    adj[u].push_back(make_pair(v,weight));
    adj[v].push_back(make_pair(u,weight));
}

void prims(vector<iPair> adj[], int source, int V) {
  
  // In here, the pq stands for pair of 
  // pair.first - distance from start vertex
  // pair.second - parent vertex, current vertex;
  priority_queue<iiPair, vector < iiPair >, greater< iiPair> > pq;
  pq.push(make_pair(0, make_pair(-1, source)));
  
  vector<bool> inMST(V, false);
  vector<int> mstWeights(V, INT_MAX);
  vector<int> parent(V, -1);
  
  while(!pq.empty()) {
      
      int parent_of_current_vertex = pq.top().second.first;
      int current_vertex = pq.top().second.second;

      if (!inMST[current_vertex]) {
        mstWeights[current_vertex] = pq.top().first;
        inMST[current_vertex] = true;
        parent[current_vertex] = parent_of_current_vertex;
      }
      pq.pop();
      
      for(int i = 0; i<adj[current_vertex].size(); i++) {
          
          if (!inMST[adj[current_vertex][i].first])
            pq.push(make_pair(adj[current_vertex][i].second + mstWeights[current_vertex], make_pair(current_vertex, adj[current_vertex][i].first)));
            
      }
      
  }
  
  for(int i = 0; i<V; i++) {
  
    cout<<"\n == Vertex # "<<i<<" == \n";
    int j = i;
    do {
        cout<<j<<"<--";
        j = parent[j];
    
    } while(j != -1);
    cout<<"\n Weight = "<<mstWeights[i]<<"\n\n";
  }
  
  
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V = 8;
    vector<iPair> adj[V];
    
    addEdge(adj, 0, 1, 1);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 1, 5, 3);
    addEdge(adj, 1, 6, 1);
    addEdge(adj, 2, 3, 2);
    addEdge(adj, 2, 4, 5);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 2);
    addEdge(adj, 4, 5, 3);
    addEdge(adj, 6, 7, 6);
    
    prims(adj, 0, V);
    
}
