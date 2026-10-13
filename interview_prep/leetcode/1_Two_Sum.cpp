class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> pnums;
        for(int i =0; i<nums.size(); i++) {

            // if (nums[i] >= target)
            //     continue;

            if (pnums.count(target-nums[i]) != 0)
                return vector<int> {pnums[target-nums[i]], i};
            pnums[nums[i]]=i;
        }

        return vector<int> {};

    }
};

