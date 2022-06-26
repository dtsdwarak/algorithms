class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low=0, high = nums.size()-1, mid;
        
        while(low <= high) {
            
            int mid = low + (high - low)/2;
            
            if (nums[mid] == target)
                return mid;
            
            else if (nums[mid] <= nums[high]) {
                
                if (target > nums[mid] && target <= nums[high]) // Compare equality at the edges. 
                    low = mid +1;
                else
                    high = mid -1;
            }
            
            else if (nums[low] <= nums[mid]) {
                
                if (target >= nums[low] && target < nums[mid]) // Compare equality at the edges. 
                    high = mid -1;
                else
                    low = mid+1;
            }
            
        }
        
        return -1;
        
    }
};
