class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int low=0, high = n-1, mid, next, prev;

        while(low <= high) {
            
            // Eliminating the default case first
            if (nums[low] <= nums[high])
                return nums[low];
            
            mid = low + (high-low)/2;
            next = (mid + 1) % n;
            prev = (mid + n -1) % n;
            
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                return nums[mid];
            
            // Low and mid are in contiguous block. So, least element must be in the other half
            else if (nums[mid] >= nums[low]) 
                low = mid +1;
            
            // high and mid are in contiguous block. So, least element must be in the other half
            else if (nums[mid] <= nums[high])
                high = mid-1;
            
        }
        
        return -1;
        
    }
};
