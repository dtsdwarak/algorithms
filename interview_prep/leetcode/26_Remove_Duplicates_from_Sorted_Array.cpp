class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j=1, i=1,item = nums[0];

        while (i < nums.size()) {
            if (nums[i] == item) {
                i++;
                continue;
            }
            item = nums[i];
            nums[j++] = nums[i];
        }

        return j;
    }
};
