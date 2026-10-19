class Solution {

private:

    bool icCyclicInDFS(vector<int> adj[], vector<int>& colors, int node) {

        colors[node] = 1; // Set to explore

        for(int i=0; i<adj[node].size(); i++) {
            
            int neighbour = adj[node][i];

            if (colors[neighbour] == 1)
                return true;
            
            if ((colors[neighbour] == 0) && icCyclicInDFS(adj, colors, neighbour))
                return true; 
        }

        colors[node] = 2; // Fully explored
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> colors(numCourses, 0);
        vector<int> adj[numCourses];

        for(auto prereq : prerequisites) {
            int start = prereq[1];
            int end = prereq[0];
            adj[start].push_back(end);
        }

        for(int i=0; i<numCourses; i++) {
            if ((colors[i] == 0) && (icCyclicInDFS(adj, colors, i))) {
                    return false;
            }
        }

        return true;
    }
};
