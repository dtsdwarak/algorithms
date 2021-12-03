class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        
        int localMax = 0, globalMax = INT_MIN;
        
        for(int i=0; i<nums.size();i++) {
            localMax = max(nums[i], nums[i]+localMax);
            globalMax = max(globalMax, localMax);
        }
        
        return globalMax;
        
    }
};
