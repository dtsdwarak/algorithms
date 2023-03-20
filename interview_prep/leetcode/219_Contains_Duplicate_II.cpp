class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, unordered_set<int>> indexesForNumber;

        for(int i=0; i<nums.size(); i++) {
            if (indexesForNumber.count(nums[i])) {
                for(auto &index : indexesForNumber[nums[i]]) {
                    if (abs(i - index) <= k)
                        return true;
                }
            }
            indexesForNumber[nums[i]].insert(i);
        }
        return false;

    }
};
