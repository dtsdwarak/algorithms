/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

using namespace std;

/** === Preprocessor Tokens === **/

#define pval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define pq priority_queue;
#define mp make_pair;
#define pb push_back;

/** === Compiler Tokens === **/

typedef long long ll;
typedef pair<int, int> pii;

/** === Vector output template === **/

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

/** === Program Logic === **/

void addEdge(vector<int> adj[], int loc1, int loc2) {
    
    adj[loc1].push_back(loc2);
    adj[loc2].push_back(loc1);
}

bool dfs(vector<int> adj[], int V, int parent, int node, vector<bool>& visited) {

    
    for(int i=0; i<adj[node].size(); i++) {
        
        int neighbour = adj[node][i];
        
        if (!visited[neighbour]) {
            visited[neighbour] = true;
            return dfs(adj, V, node, neighbour, visited);
        } else {
            if (neighbour != parent)
                return true;
        }
        
    }
    
    return false;
}

bool isCyclic(vector<int> adj[], int V) {

    vector<bool> visited(V, false);
    for(int i=0; i<V; i++) {
        for(int j=0; j<adj[i].size(); j++) {
            visited[i][j] = true;
            int node = adj[i][j];
            if (!visited[node] && dfs(adj, V, -1, node, visited))
                return true;
        }
    }
    
    return false;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V=10;
    vector<int> adj[V];
    
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    //addEdge(adj, 3, 1);
    
    cout<<"The graph is "<<(isCyclic(adj, V) ? "cyclic" : "acyclic");
    
           
    return 0;
    
}
