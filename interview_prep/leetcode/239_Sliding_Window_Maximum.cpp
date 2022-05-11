class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        multiset<int> ms;
        int i=0, previousIndexElement = nums[i], max;
        
        while(i < k) {
            ms.insert(nums[i]);
            i++;
        }
        
        for(; i<nums.size(); i++) {
            
            max = *ms.rbegin();
            ans.push_back(max);
            auto itr = ms.find(previousIndexElement);
            if (itr != ms.end())
                ms.erase(itr);
            ms.insert(nums[i]);
            previousIndexElement = nums[i-k+1];
            
        }
        
        max = *ms.rbegin();
        ans.push_back(max);
        
        return ans;
        
    }
};
