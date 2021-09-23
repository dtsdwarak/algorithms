class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int nonZeroIndex = 0, zeroCount=0;
        
        for(int i=0; i<nums.size(); i++) {
            
            if (nums[i] == 0)
                zeroCount++;
            else {
                nums[nonZeroIndex] = nums[i];
                nonZeroIndex++;
            }
        }
        
        for(int i=0; i<zeroCount; i++)
            nums[nums.size()-1-i] = 0;
        
    }
};
