class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int even=0, odd=nums.size()-1;
        
        while(even < odd) {
            
            if (nums[even] & 1) {
                while(even < odd && (nums[odd] & 1)) {
                    odd--;
                }
                if (even < odd) {
                    swap(nums[even], nums[odd]);
                    even++;
                    odd--;
                }
            }
            else
                even++;
        }
        
        return nums;
        
    }
};
