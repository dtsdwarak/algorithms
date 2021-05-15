class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        stack<int> stk;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            
            while (!stk.empty() && stk.top() > nums[i] && (n - i > k - stk.size())) // && n-i >= k)
                stk.pop();
            
            if (stk.size() < k)
                stk.push(nums[i]);
        }
        
        vector<int> ans(k);
        int i = k-1;
        while(!stk.empty()) {
            // cout<<"i value = "<<i<<" top value = "<<stk.top()<<endl;
            
            ans[i] = stk.top();
            stk.pop();
            i--;
        }
        
        return ans;
        
    }
};
