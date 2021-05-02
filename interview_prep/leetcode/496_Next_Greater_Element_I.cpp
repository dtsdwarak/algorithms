class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> nums2Map;
        stack<int> s;
        
        s.push(nums2[nums2.size() -1]);
        
        // Process nums2
        for(int i=nums2.size()-1; i>-1; i--) {
            while (!s.empty() && s.top() <= nums2[i])
                s.pop();
            
            nums2Map[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        
        vector<int> ans;
        
        for(int i: nums1)
            ans.push_back(nums2Map[i]);
        
        return ans;
    }
};
