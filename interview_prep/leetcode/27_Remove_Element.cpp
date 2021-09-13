class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        
        set<int> occurenceIndex;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            if (nums[i] == val)
                occurenceIndex.insert(i);
        }
        
        int index=0,i=0;
        
        for(;i<n;i++) {
            if (occurenceIndex.find(i) != occurenceIndex.end()) {
                continue;
            }
            nums[index]=nums[i];
            index++;
        }
        
        for(;i<n;i++)
            nums[i] = val;
        
        return nums.size()-occurenceIndex.size();
    }
};
