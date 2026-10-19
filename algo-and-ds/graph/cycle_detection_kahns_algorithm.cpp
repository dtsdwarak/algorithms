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

bool isCyclic(vector<int> adj[], int V) {
    
    // In-Degree: To denote # of incoming edges.
    vector<int> indeg(V, 0);
    
    for(int i=0; i < V; i++) {
        for(auto neighbour : adj[i]) {
            indeg[neighbour]++;
        }
    }
    
    queue<int> queue_;
    
    for(int i=0; i<V; i++) {
        if (indeg[i] == 0)
            queue_.push(i);
    }
    
    int processed = 0;
    while(!queue_.empty()) {
    
        int node = queue_.front();
        queue_.pop();
        
        processed++;
        
        for(int i=0; i<adj[node].size();i++) {
            int neighbour = adj[node][i];
            indeg[neighbour]--;
            
            if (indeg[neighbour] == 0)
                queue_.push(neighbour);
        }
        
    }
    
    if (processed != V)
        return true;
    
    return false;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V=10;
    vector<int> adj[V];
    
    
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 2);
    
    cout<<(isCyclic(adj, V) ? "cyclic" : "acyclic");
           
    return 0;
    
}
