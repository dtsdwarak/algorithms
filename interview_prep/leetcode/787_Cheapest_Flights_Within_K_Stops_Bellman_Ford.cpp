#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int start;
    int dest;
    int cost;
};

struct Graph {
    int V;
    vector<Edge> edges;
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 1. Build the graph structure
        Graph graph;
        graph.V = n;
        for (const auto& flight : flights) {
            graph.edges.push_back({flight[0], flight[1], flight[2]});
        }

        // 2. Initialize distance vector
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // A path with at most K stops means we can take at most K + 1 flights (edges).
        // Therefore, we run the relaxation loop exactly K + 1 times.
        for (int i = 0; i <= k; i++) {
            // CRITICAL: Duplicate the distance array from the previous round.
            // This prevents updates from chaining together within the same iteration.
            vector<int> tempDist = dist;

            for (const auto& edge : graph.edges) {
                // If the source of the edge was reachable in the PREVIOUS round
                if (dist[edge.start] != INT_MAX) {
                    // Update the TEMPORARY array using the valid snapshot from the last round
                    if (tempDist[edge.dest] > dist[edge.start] + edge.cost) {
                        tempDist[edge.dest] = dist[edge.start] + edge.cost;
                    }
                }
            }
            // Move the synchronized updates into our primary distance tracker
            dist = tempDist;
        }

        // Return -1 if dst is unreachable within the K-stop limit
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

