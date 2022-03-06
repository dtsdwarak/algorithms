class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        if (k >= nums.size())
            return nums;
        
        priority_queue<pair<int, int>> pq;
        
        for(int i=0; i<nums.size(); i++)
            pq.push({nums[i], i});
        
        set<int> topKIndices;
        
        while(k--) {
            topKIndices.insert(pq.top().second);
            pq.pop();
        }
        
        vector<int> ans;
        
        for(auto index : topKIndices) 
            ans.push_back(nums[index]);
        
        return ans;
    }
};
