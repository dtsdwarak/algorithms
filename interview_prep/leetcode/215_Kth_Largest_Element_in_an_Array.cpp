/*
* Reference
* https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue <int> pq;
        
        for(int i: nums)
            pq.push(i);
        
        int ans;
        
        while(k--) {
            ans = pq.top();
            pq.pop();
        }
        
        return ans;
        
    }
};


