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

void addEdge(vector<int> adj[], int start, int destination) {
    adj[start].push_back(destination);
}

bool isCyclicInDFS(vector<int> adj[], vector<int>& colors, int node) {
    
    // Mark current node as "in-exploration".
    colors[node] = 1;
    
    for(size_t i=0;i<adj[node].size();i++) {
        int neighbour = adj[node][i];
        
        if (colors[neighbour] == 1)
            return true;
        
        if (colors[neighbour] == 0) {
            if (isCyclicInDFS(adj, colors, neighbour))
                return true;
        }
    }
    
    colors[node] = 2; // Fully explored.
    return false;
}

/*
 * Color States:
 * 
 * 0 - White; Not visited/explored
 * 1 - Gray; Currently under exploration.
 * 2 - Black; Completely explored.
 * 
 */
bool isCyclic(vector<int> adj[], int V) {
    
    
    vector<int> colors(V, 0);
    
    for(int i=0; i<V; i++) {
        if (colors[i] == 0) {
            if (isCyclicInDFS(adj, colors, i))
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
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 1);
    
           
    cout<<"The given graph is "<<(isCyclic(adj, V) ? "cyclic" : "acyclic");   
    
    return 0;
    
}
