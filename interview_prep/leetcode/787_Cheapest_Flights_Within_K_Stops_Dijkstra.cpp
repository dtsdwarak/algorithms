#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 1. Build the Adjacency List: node -> list of {neighbor, cost}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // 2. dist[node][flights_taken] tracks the minimum cost to reach a node 
        // with an exact number of flights taken.
        // Maximum flights allowed is k + 1. Array size needs to be (k + 2).
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        // Min-Heap stores: {cost, current_node, flights_taken}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();

            int currentCost = current[0];
            int u = current[1];
            int flightsTaken = current[2];

            // Because it's a min-heap, the first time we pop the destination,
            // it is guaranteed to be the cheapest valid path.
            if (u == dst) return currentCost;

            // If we have already taken the maximum allowed flights (k + 1), 
            // we cannot catch another flight from this city.
            if (flightsTaken > k) continue;

            // Explore all neighboring flights
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int cost = neighbor.second;
                int nextFlights = flightsTaken + 1;

                // Relax the edge: only push if this path is cheaper than 
                // any previous path reaching 'v' with the exact same number of flights.
                if (currentCost + cost < dist[v][nextFlights]) {
                    dist[v][nextFlights] = currentCost + cost;
                    pq.push({currentCost + cost, v, nextFlights});
                }
            }
        }

        return -1; // Destination unreachable within the stop limit
    }
};

