class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        
        
        if (nums.size() == 0)
            return nums[0];
        
        sort(nums.begin(), nums.end());
        int n=nums.size(), answer= nums[n-1] - nums[0], minValue, maxValue;
        
        for(int i=0; i<n-1; i++) {
            
            minValue = min(nums[0]+k, nums[i+1]-k);
            maxValue = max(nums[n-1]-k, nums[i]+k);
            
            answer = min(answer, maxValue - minValue);
        }
        
        return answer;
    }
};
