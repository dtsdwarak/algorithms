class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for(int num: nums)
            val ^= num;
        return val;
    }
};
