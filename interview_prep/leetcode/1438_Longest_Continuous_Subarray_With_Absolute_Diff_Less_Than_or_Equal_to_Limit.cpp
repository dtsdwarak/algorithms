class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        multiset<int> m;
        int j=0, maxLength=1;
        
        for(int i=0; i<nums.size(); i++) {
            
            m.insert(nums[i]);
            
            while(!m.empty() && *(m.rbegin()) - *(m.begin()) > limit)
                m.erase(m.find(nums[j++]));
            
            maxLength = max(maxLength, i-j+1);
        }
        
        return maxLength;
        
    }
};
