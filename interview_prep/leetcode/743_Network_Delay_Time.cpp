class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<int>> adjMatrix = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        
        for(auto entry : times) {
            adjMatrix[entry[0]][entry[1]] = entry[2];
        }
        
        vector<int> nodeCosts(n+1, INT_MAX);
        nodeCosts[0] = 0;
        nodeCosts[k] = 0;
        
        // To start traversing the node k
        for(int i=1; i<n+1; i++) {
            if (adjMatrix[k][i] != -1 && (nodeCosts[i] > adjMatrix[k][i]))
                dfs(adjMatrix, nodeCosts, k, i, 0);
        }
        
        int maxValue = *max_element(nodeCosts.begin(), nodeCosts.end());
        
        return maxValue == INT_MAX ? -1 : maxValue;
        
    }
    
    void dfs(
        vector<vector<int>> &adjMatrix, 
        vector<int> &nodeCosts,
        int sourceNode, 
        int destNode, 
        int costSoFar) {
        
        int costTillDestination = adjMatrix[sourceNode][destNode] + costSoFar;
        nodeCosts[destNode] = min(nodeCosts[destNode], costTillDestination);
        
        for(int i=1; i<adjMatrix.size(); i++) {
            if (adjMatrix[destNode][i] != -1 && (nodeCosts[i] > costTillDestination +adjMatrix[destNode][i]))
                dfs(adjMatrix, nodeCosts, destNode, i, costTillDestination);
        }
        
    }
    
};
