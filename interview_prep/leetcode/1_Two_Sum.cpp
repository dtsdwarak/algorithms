class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueIndexMap;
        
        for(int i=0; i<nums.size(); i++) {
            if (valueIndexMap.count(target-nums[i])) {
                return vector<int>{i, valueIndexMap[target-nums[i]]};
            }
            valueIndexMap[nums[i]] = i;
        }
        
        return vector<int>();
    }
};
