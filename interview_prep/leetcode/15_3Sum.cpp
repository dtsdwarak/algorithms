class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if (nums.size() < 3)
            return {};
        
        set<tuple<int, int, int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++) {
            
            int target = -nums[i];
            int front = i+1;
            int back = nums.size() -1;
            
            while(front < back) {
                
                if (nums[front] + nums[back] == target) {
                    ans.insert(make_tuple(nums[i], nums[front], nums[back]));
                    front++;
                    back--;
                }
                else if (nums[front] + nums[back] < target)
                    front++;
                else
                    back--;
                
            }
        }
        
        vector<vector<int>> answer;
        
        for(auto &i : ans)
            answer.push_back({get<0>(i), get<1>(i), get<2>(i)});
        
        return answer;
        
    }
};

