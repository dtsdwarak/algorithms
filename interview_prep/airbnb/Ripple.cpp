/*
"In a popular travel destination, several Airbnb hosts offer unique accommodations. Each host has a listing located at a specific point in the city and can influence other listings nearby. Each property is represented by a 0-indexed 2D integer array listings, where listings[i] = [xi, yi, ri]. Here, (xi, yi) represents the X-coordinate and Y-coordinate of the i-th host's property, while ri denotes the radius of their influence.


When a guest books a property, that booking will result in nearby hosts to receive a booking as well, provided their listings fall within the influence radius of the original booking. The influence of one property can create a ripple effect, activating multiple bookings.
Your task is to determine the maximum number of listings that can receive bookings if a guest initially books only one property."

----

This problem can be modeled as a **directed graph traversal (BFS or DFS)**.

### Core Intuition & Approach

1. **Graph Construction:** Each listing acts as a node. There is a directed edge from listing $i$ to listing $j$ if the Euclidean distance between their coordinates is less than or equal to the radius $r_i$ of listing $i$. Note that this relationship is **asymmetric**—listing $i$ might reach listing $j$, but $j$ might not necessarily reach $i$ due to different radii.
2. **Chain Reaction Simulation:** We simulate a booking starting from each listing independently using a Breadth-First Search (BFS). A `visited` tracker ensures we count each unique property activated during the cascade.
3. **Maximum Optimization:** We track the maximum number of properties reached across all possible starting listings.

---

### Complexity Analysis

* **Time Complexity:** $\mathcal{O}(N^2)$ to compute pairwise squared distances and construct the graph, plus $\mathcal{O}(N \cdot (V + E))$ for running BFS from every node, yielding an overall time complexity of $\mathcal{O}(N^3)$ in the worst-case dense graph scenario (where $N \le 100$, this executes well within the limits).
* **Space Complexity:** $\mathcal{O}(N^2)$ to store the adjacency list graph and $\mathcal{O}(N)$ for the BFS queue and visited tracking arrays.



*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class AccommodationRecommender {
public:
    static int maximumBookings(const vector<vector<int>>& listings) {
        int n = listings.size();
        if (n == 0) return 0;

        // Step 1: Build the directed adjacency list
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            long long x1 = listings[i][0];
            long long y1 = listings[i][1];
            long long r1 = listings[i][2];
            long long r1_sq = r1 * r1;

            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                long long x2 = listings[j][0];
                long long y2 = listings[j][1];

                long long dx = x1 - x2;
                long long dy = y1 - y2;
                long long dist_sq = dx * dx + dy * dy;

                // If listing j is within the influence radius of listing i
                if (dist_sq <= r1_sq) {
                    adj[i].push_back(j);
                }
            }
        }

        // Step 2: Run BFS from each listing to find the maximum ripple effect
        int max_reached = 0;

        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            queue<int> q;
            
            q.push(i);
            visited[i] = true;
            int count = 0;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                count++;

                for (int neighbor : adj[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            max_reached = max(max_reached, count);
        }

        return max_reached;
    }
};

int main() {
    vector<vector<int>> listings = {
        {1, 2, 3},
        {2, 3, 1},
        {3, 4, 2},
        {4, 5, 3},
        {5, 6, 4}
    };

    cout << "Maximum listings booked: " << AccommodationRecommender::maximumBookings(listings) << endl;
    return 0;
}