class Solution {
public:
    string reverseParentheses(string s) {
        
        queue<char> q;
        stack<char> stk;
        
        for(char i: s) {
            
            if (i == ')') {
                
                while(stk.top() != '(') {
                    q.push(stk.top());
                    stk.pop();
                }
                
                stk.pop();
                
                while(!q.empty()) {
                    stk.push(q.front());
                    q.pop();
                }
                
            }
            else
                stk.push(i);
            
        }
        
        string ans;
        
        while(!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        
        return ans;
        
        
    }
};
