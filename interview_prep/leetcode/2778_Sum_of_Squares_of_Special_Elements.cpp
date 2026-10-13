class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        
        int sum = 0, n = nums.size();
        for(int i=0; (i+1) * (i+1) <= n; i++) {
            if (n % (i+1) == 0) {
                sum += nums[i] * nums[i];
                int other = n / (i+1);
                if (other != i+1) {
                    sum += nums[other-1] * nums[other-1];
                }
            }
        }

        return sum;
    }
};
