class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.size() < 2) {
            return nums.size();
        }
    
        int current = nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); i++) {
            
            if (nums[i] != current) {
                count = 1;
                current = nums[i];
                continue;
            }
            
            if (nums[i] == current)
                count++;
            
            if (count > 2)
                nums[i] = INT_MIN;
        }

        int i=0, j=0;
        for(int i=0; i<nums.size();i++) {
            
            if (nums[i] == INT_MIN)
                continue;
            
            nums[j] = nums[i];
            j++;

        }

        return j;

    }
};
