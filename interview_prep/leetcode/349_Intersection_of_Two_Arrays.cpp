class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> numberSet(nums1.begin(), nums1.end());
        set<int> intersection;
        
        for(int i : nums2) {
            
            if (numberSet.count(i))
                intersection.insert(i);
        }
        
        return vector<int>(intersection.begin(), intersection.end());
    }
};
