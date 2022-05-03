/*

Approach - 

For a number to remain untouched, 

1. The number should not have any number smaller than it on the right side
2. The number should not have any number greater than it on the left side.

For #1 -> Create a vector with min number from right
For #2 -> Create a vector with max number from left;

*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> minFromRight(nums.size());
        vector<int> maxFromLeft(nums.size());
        
        int maxLeft = INT_MIN;
        for(int i=0;  i<nums.size(); i++) {
            maxLeft = max(nums[i], maxLeft);
            maxFromLeft[i] = maxLeft;
        }
        
        int minRight = INT_MAX;
        for(int i=nums.size()-1;  i>-1; i--) {
            minRight = min(nums[i], minRight);
            minFromRight[i] = minRight;
        }
        
        int start=0, end=nums.size()-1;
        
        for(; start<nums.size() && nums[start] == minFromRight[start]; start++);
        for(; end>-1 && nums[end] == maxFromLeft[end]; end--);
        
        if (start >= nums.size())
            return 0;
        return end-start+1;
        
    }
};



/*

2 6 4 8 10  9 15
2 6 8 4 10  9 15
2 4 6 8  9 10 15
 

*/
