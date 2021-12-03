/*
* We recursively reach every point "reachable" from 0 (the starting index) and 
* there-after from those indexes compute if we can reach the end point. If so, return the 
* # of hops required.
* 
* We store the intermediate results so, the "Number of hops required" is not computed everytime
* when we see a previous index within the "fetchHopsRequired" function.
* 
* Thus, the below solution is considered a dynamic programming solution.
*/
class Solution {
    
    vector<int> hopsRequired;
    
    int fetchHopsRequired(vector<int> &nums, int index) {
        
        if (hopsRequired[index] != -1)
            return hopsRequired[index];
        else if (index + nums[index] >= nums.size()-1)
            return 1;
        
        int minHopsRequired = 10000;
        
        for(int i=1; i<=nums[index] && index + i < nums.size(); i++) {
            minHopsRequired = min(minHopsRequired, fetchHopsRequired(nums, index+i));
        }
        
        hopsRequired[index] = minHopsRequired+1;
        return minHopsRequired+1;
        
    }
    
public:
    int jump(vector<int>& nums) {
        
        if (nums.size() == 1)
            return 0;
        
        hopsRequired = vector<int>(nums.size(), -1);
        return fetchHopsRequired(nums, 0);
    }
};
