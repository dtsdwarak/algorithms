class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(int &i: nums)
            us.insert(i);
        return us.size() < nums.size();
    }
};
