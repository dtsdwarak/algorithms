class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        if (val <0 || val > 100)
            return 0;

       int j=0;
       for(int i=0;i<nums.size();i++) {
            if (nums[i] != val) {
                nums[j++] = nums[i]; 
            }
       }

       return j;

    }
};
