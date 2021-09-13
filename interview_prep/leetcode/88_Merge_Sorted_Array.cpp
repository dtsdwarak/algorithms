class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if (nums1.size() == 0) {
            nums1 = nums2;
            return;
        }
        else if (nums2.size() == 0)
            return;
        
        vector<int> nums;
        
        int i=0, j=0;
        
        while(i < m && j < n) {
            
            if (nums1[i] < nums2[j])
                nums.push_back(nums1[i++]);
            else
                nums.push_back(nums2[j++]);
            
        }
        
        while (i < m)
            nums.push_back(nums1[i++]);
        while (j < n)
            nums.push_back(nums2[j++]);
        
        nums1=nums;
    }
};
