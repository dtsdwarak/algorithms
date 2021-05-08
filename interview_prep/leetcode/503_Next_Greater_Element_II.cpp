/*
* Basic idea is to traverse through the input array twice.
* In first pass, we get the next greater element within fixed the array range.
* In the 2nd pass when we have the stack filled up with larger elements, 
* the elements which previously had no larger elements will also get filled up. 
* 
* Solution reference - 
* https://www.geeksforgeeks.org/find-the-next-greater-element-in-a-circular-array-set-2/
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> s;
        vector<int> ans(nums.size(), INT_MIN);
        int count=0;
        
        while(count++ < 2) {
        
            for(int i=nums.size()-1; i>-1; i--) {

                if (ans[i] == INT_MIN) {

                    if (!s.empty()) {

                        while(!s.empty() && s.top() <= nums[i])
                            s.pop();

                        ans[i] = s.empty() ? INT_MIN : s.top();
                    }
                    else 
                        ans[i] = INT_MIN;
                    
                    if (count < 2)
                        s.push(nums[i]);
                }

            }
            
        }
        
        for(int i=0; i<ans.size(); i++)
            ans[i] = (ans[i] == INT_MIN) ? -1 : ans[i];
        
        return ans;
        
    }
};
