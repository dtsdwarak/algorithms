/*
* We recursively reach every point "reachable" from 0 (the starting index) and 
* there-after from those indexes and check if we can reach the end point.
* We store the intermediate results so, the "reachability" factor is not computed everytime
* when we see a previous index within the "canJumpFrom" function.
* 
* Thus, the below solution is considered a dynamic programming solution.
*/
class Solution {
    
    vector<int> jumpStatus;
    
    int canJumpFrom(vector<int>& nums, int i) {
        
        if (jumpStatus[i] != -1)
            return jumpStatus[i];
        else if (i + nums[i] >= nums.size()-1) {
            jumpStatus[i] = 1;
            return 1;
        }
        
        int canJump = 0;
        for(int k=1; k<=nums[i] && i+k<nums.size(); k++) {
            canJump |= canJumpFrom(nums,i+k);
            if (canJump) {
                jumpStatus[i] = 1;
                return 1;
            }
        }
        
        jumpStatus[i] = 0;
        return 0;
    }
    
public:
    bool canJump(vector<int>& nums) {
        
        jumpStatus = vector<int>(nums.size(),-1);
        if (canJumpFrom(nums, 0))
            return true;
        return false;
        
    }
};
