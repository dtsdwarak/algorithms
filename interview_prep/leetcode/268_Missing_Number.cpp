class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int ans = 0, i=0;
        
        for(; i<nums.size(); i++)
            ans ^= nums[i] ^ i;
        
        return ans ^ i;
        
    }
};
