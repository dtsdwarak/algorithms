/*
"A set of friends is planning a summer vacation on Airbnb. Independently, they search for listings and each come up with a list of preferences. They then meet in person to compare preferences. Each person comes prepared with their preferences as an ordered list of listing_ids.

Input: You are given a dictionary as input, where each key is a friend’s name and the value associated with that key is a list of integers, representing that friend’s ordered preferences. An example:

var preferences = {
  ""Mary"": [10, 2, 5, 20],
  ""John"": [3, 10, 5, 18],
  ""Pete"": [4, 3, 8],
  ""Kate"": [3, 7, 18, 1],
  ""Steven"": [9]
}

Task 1: First, the group would like to know if it’s possible to generate a global list of preferences containing all the listings present that also respects each of their individual preferences. Given the input, write a function that returns a boolean indicating whether such a global list is possible.

Task 2: After some thought, it is determined that such a global list is possible. Write a function that takes the input and generates one possible global list.

Task 3: John decides that since he is planning the trip, his preferences should be weighted more than everyone else’s. Write a function that takes the input and generates a global list that in addition to respecting everyone’s preferences, guarantees that John’s preferences show up strictly before anyone else’s."

-----------


Here is a comprehensive breakdown of the **Vacation Planner** problem, how it's modeled, and how the three tasks work together.

---

### 1. The Core Mental Model: Resolving Conflicts

Imagine a group of friends trying to make a shared travel itinerary. Each friend brings their own wishlist sorted by preference (e.g., Mary wants listing 10 before 2, but John wants listing 3 before 10).

To combine these into a single **global list**, we have to respect two fundamental rules:

1. **Preserve Relative Order:** If person $X$ puts item $A$ before item $B$, then $A$ *must* appear before $B$ in the final global list ($A \to B$).
2. **No Contradictions (Cycles):** If Mary says $A \to B$ and John says $B \to A$, an impossible paradox is created (a cycle).

We solve this using **Directed Acyclic Graphs (DAG)** and **Topological Sorting (Kahn’s Algorithm)**.

---

### 2. Graph Construction (The Foundation)

Before tackling any tasks, all friend preferences are translated into a graph:

* **Nodes:** Every unique listing ID mentioned across all friend wishlists.
* **Directed Edges:** For any friend's preference list `[u, v, w]`, we add directed edges: $u \to v$ and $v \to w$.
* **In-Degree Tracking:** We count how many incoming arrows point to each node. An in-degree of `0` means a listing has no prerequisites holding it back and is immediately ready to be scheduled.

---

### 3. Task-by-Task Breakdown & Reusability

Our implementation follows a clean, modular structure where each task handles its own responsibility, but subsequent tasks **reuse Task 1** to validate feasibility before proceeding.

#### Task 1: Feasibility Check (`isGlobalListPossible`)

* **What it does:** Determines whether a valid global timeline can exist.
* **How it works:** It runs **Kahn’s Algorithm** (BFS processing nodes with `in-degree == 0`). As nodes are processed, their outgoing neighbors' in-degrees are decremented. If all unique listings are successfully processed, the graph is acyclic and returns `true`. If a cycle exists, the queue runs out of available 0-in-degree nodes early, and it returns `false`.

#### Task 2: Generating the Global List (`generateGlobalList`)

* **Reuses Task 1:** It starts by calling `isGlobalListPossible(preferences)`. If a cycle exists, it immediately returns an empty list `{}`, avoiding wasted computation.
* **How it works:** If feasible, it runs the topological sort engine again, pushing available 0-in-degree nodes into a queue. To ensure deterministic output, ties among 0-in-degree nodes are sorted alphabetically/numerically, building the final sequence step-by-step.

#### Task 3: Weighted Priority (`generateWeightedGlobalList`)

* **Reuses Task 1:** Just like Task 2, it checks `isGlobalListPossible(preferences)` first to guarantee feasibility.
* **How it works:** John needs his preferences to appear strictly before everyone else's *without violating any other friend's internal ordering*.
* **The Queue Customization:** When picking the next node from all currently available 0-in-degree candidates, a custom comparator checks if any available listing belongs to John. If so, John's listing gets picked first. This ensures John's items cluster at the front of the timeline as early as topological constraints allow.

---

### Why This Architecture Shines

* **Separation of Concerns:** Each method has a single, well-defined purpose.
* **Fail-Fast Efficiency:** Tasks 2 and 3 don't attempt to generate permutations on an impossible, cyclic graph—they delegate feasibility validation to Task 1 instantly.

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class VacationPlanner {
private:
    // Shared graph construction helper used across all methods
    struct Graph {
        unordered_set<int> unique_listings;
        unordered_map<int, unordered_set<int>> adj;
        unordered_map<int, int> in_degree;
    };

    static Graph buildGraph(const unordered_map<string, vector<int>>& preferences) {
        Graph g;
        for (const auto& [friend_name, pref_list] : preferences) {
            for (int listing : pref_list) {
                g.unique_listings.insert(listing);
                g.in_degree[listing] = 0;
            }
        }

        for (const auto& [friend_name, pref_list] : preferences) {
            for (size_t i = 0; i + 1 < pref_list.size(); ++i) {
                int u = pref_list[i];
                int v = pref_list[i + 1];
                if (g.adj[u].find(v) == g.adj[u].end()) {
                    g.adj[u].insert(v);
                    g.in_degree[v]++;
                }
            }
        }
        return g;
    }

public:
    // Task 1: Check if a valid global preference list is possible (Feasibility check)
    static bool isGlobalListPossible(const unordered_map<string, vector<int>>& preferences) {
        Graph g = buildGraph(preferences);
        queue<int> q;
        for (int listing : g.unique_listings) {
            if (g.in_degree[listing] == 0) {
                q.push(listing);
            }
        }

        int processed_count = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            processed_count++;

            for (int neighbor : g.adj[curr]) {
                g.in_degree[neighbor]--;
                if (g.in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return processed_count == g.unique_listings.size();
    }

    // Task 2: Generate one possible global list
    // Reuses Task 1 output (isGlobalListPossible) to short-circuit if a cycle exists.
    static vector<int> generateGlobalList(const unordered_map<string, vector<int>>& preferences) {
        // Reuse Task 1 output
        if (!isGlobalListPossible(preferences)) {
            return {}; // Cycle detected, impossible to generate
        }

        Graph g = buildGraph(preferences);
        queue<int> q;
        vector<int> zero_deg;
        for (int listing : g.unique_listings) {
            if (g.in_degree[listing] == 0) {
                zero_deg.push_back(listing);
            }
        }
        sort(zero_deg.begin(), zero_deg.end());
        for (int node : zero_deg) {
            q.push(node);
        }

        vector<int> result;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);

            vector<int> neighbors(g.adj[curr].begin(), g.adj[curr].end());
            sort(neighbors.begin(), neighbors.end());

            for (int neighbor : neighbors) {
                g.in_degree[neighbor]--;
                if (g.in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return result;
    }

    // Task 3: Generate global list with John's preferences weighted strictly first
    // Reuses Task 1 output for feasibility validation.
    static vector<int> generateWeightedGlobalList(const unordered_map<string, vector<int>>& preferences, const string& priority_person = "John") {
        // Reuse Task 1 output
        if (!isGlobalListPossible(preferences)) {
            return {};
        }

        auto it = preferences.find(priority_person);
        if (it == preferences.end()) {
            return generateGlobalList(preferences);
        }

        Graph g = buildGraph(preferences);
        unordered_set<int> priority_items(it->second.begin(), it->second.end());

        vector<int> result;
        while (result.size() < g.unique_listings.size()) {
            vector<int> available;
            for (int listing : g.unique_listings) {
                if (g.in_degree[listing] == 0 && find(result.begin(), result.end(), listing) == result.end()) {
                    available.push_back(listing);
                }
            }

            if (available.empty()) return {};

            // Prioritize John's items when selecting from available 0-indegree nodes
            sort(available.begin(), available.end(), [&](int a, int b) {
                bool a_prio = priority_items.count(a) > 0;
                bool b_prio = priority_items.count(b) > 0;
                if (a_prio != b_prio) return a_prio > b_prio;
                return a < b;
            });

            int curr = available[0];
            result.push_back(curr);
            g.in_degree[curr] = -1;

            for (int neighbor : g.adj[curr]) {
                g.in_degree[neighbor]--;
            }
        }

        return result;
    }
};

int main() {
    unordered_map<string, vector<int>> preferences = {
        {"Mary", {10, 2, 5, 20}},
        {"John", {3, 10, 5, 18}},
        {"Pete", {4, 3, 8}},
        {"Kate", {3, 7, 18, 1}},
        {"Steven", {9}}
    };

    cout << "Task 1 - Is Global List Possible? " 
         << (VacationPlanner::isGlobalListPossible(preferences) ? "True" : "False") << "\n\n";

    cout << "Task 2 - Generated Global List:\n[ ";
    vector<int> global_list = VacationPlanner::generateGlobalList(preferences);
    for (int id : global_list) cout << id << " ";
    cout << "]\n\n";

    cout << "Task 3 - Weighted Global List (John's Priority):\n[ ";
    vector<int> weighted_list = VacationPlanner::generateWeightedGlobalList(preferences, "John");
    for (int id : weighted_list) cout << id << " ";
    cout << "]\n\n";

    return 0;
}