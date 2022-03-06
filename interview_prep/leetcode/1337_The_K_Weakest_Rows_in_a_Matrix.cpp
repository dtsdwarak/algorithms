class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> >> pq;
        
        for(int rowIndex = 0; rowIndex < mat.size(); rowIndex++) {
            int i =0;
            for(; i< mat[rowIndex].size() && mat[rowIndex][i] == 1; i++);
            pq.push({i, rowIndex});
        }
        
        vector<int> ans;
        while(!pq.empty() && k > 0) {
            
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
            
        }
        
        return ans;
        
    }
};
