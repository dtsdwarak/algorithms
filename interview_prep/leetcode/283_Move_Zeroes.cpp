class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        if (nums.size() < 2)
            return;

        int i=0,j=0;
        for(; i<nums.size(); i++) {
            if (nums[i] != 0)
                nums[j++] = nums[i];
        }

        for(;j<nums.size();j++){
            nums[j] =0;
        }

    }
};
