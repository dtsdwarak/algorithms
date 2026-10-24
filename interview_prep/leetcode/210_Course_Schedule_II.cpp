class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0); // To track a node's indegree.

        // Fill the adj list
        for(const auto& prereq: prerequisites) {
            int start = prereq[1];
            int end = prereq[0];

            adj[start].push_back(end);
            indegree[end]++;
        }

        queue<int> queue_;

        for(int i=0; i<numCourses; i++) {
            if (indegree[i] == 0)
                queue_.push(i);
        }

        vector<int> topologicalOrder;

        while(!queue_.empty()) {

            int edge = queue_.front();
            queue_.pop();

            topologicalOrder.push_back(edge);

            for(int i=0; i<adj[edge].size(); i++) {
                int neighbour = adj[edge][i];
                indegree[neighbour]--;

                if (indegree[neighbour] == 0)
                    queue_.push(neighbour);
            }
        }

        if (topologicalOrder.size() == numCourses)
            return topologicalOrder;
        
        return {};

    }
};
