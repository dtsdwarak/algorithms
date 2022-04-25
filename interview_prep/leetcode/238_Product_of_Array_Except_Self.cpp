class Solution {
    
    
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> forwardProduct(nums.size()); forwardProduct[0] = nums[0];
        vector<int> reverseProduct(nums.size()); reverseProduct[nums.size()-1] = nums[nums.size()-1];
        
        for(int i=1; i<nums.size(); i++)
            forwardProduct[i] = nums[i] * forwardProduct[i-1];
        
        for(int i=nums.size()-2;i>-1; i--)
            reverseProduct[i] = nums[i] * reverseProduct[i+1];
        
        vector<int> ans(nums.size());
        
        for(int i=0; i<nums.size(); i++)
            ans[i] = (i == 0 ? 1 : forwardProduct[i-1]) * (i == nums.size()-1 ? 1 : reverseProduct[i+1]);
        
        return ans;
        
    }
};
