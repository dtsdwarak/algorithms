/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

#define pval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using namespace std;

typedef long long ll;

struct Edge {
    int src;
    int dest;
    int weight;
};

struct Graph {
    int V;
    int E;
    Edge *edges;
    
    Graph(int numVertices, int numEdges) {
      this->V = numVertices;
      this->E = numEdges;
      this->edges = new Edge[E];
    }
};


void bellmanFord(Graph *graph, int source) {
  
    int V = graph->V;
    int E = graph->E;
    
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;
    
    for(int i =0; i <= V-1; i++) {
        for(int j =0; j < E; j++) {
            if (dist[graph->edges[j].src] != INT_MAX && (dist[graph->edges[j].dest] > dist[graph->edges[j].src] + graph->edges[j].weight))
              dist[graph->edges[j].dest] = dist[graph->edges[j].src] + graph->edges[j].weight;
        }
    }
    
    for(int i =0; i <= V-1; i++) {
        for(int j =0; j < E; j++) {
            if (dist[graph->edges[j].src] != INT_MAX && (dist[graph->edges[j].dest] > dist[graph->edges[j].src] + graph->edges[j].weight)) {
              cout<<"\n Negative edge cycle present";
              exit(0);
            }
        }
    }
    
    for(int i=0;i<dist.size();i++) {
        cout<<"\n Distance of vertex "<<i<<" from source = "<<dist[i];
    }
  
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V = 5;
    int E = 8;
    
    Graph *graph = new Graph(V, E);
    
    graph->edges[0] = {0,1,-1};
    graph->edges[1] = {0,2,4};
    graph->edges[2] = {1,2,3};
    graph->edges[3] = {1,3,2};
    graph->edges[4] = {1,4,2};
    graph->edges[5] = {3,2,5};
    graph->edges[6] = {3,1,1};
    graph->edges[7] = {4,3,-3};
    
    bellmanFord(graph, 0);
    
}
