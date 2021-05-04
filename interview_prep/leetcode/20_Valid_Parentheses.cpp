class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        
        for(char i: s) {
            switch(i) {
                case '}' : {
                    if (stk.empty() || stk.top() != '{')
                        return false;
                    stk.pop();
                    break;
                }
                case ')': {
                    if (stk.empty() || stk.top() != '(')
                        return false;
                    stk.pop();
                    break;
                }
                case ']' : {
                    if (stk.empty() || stk.top() != '[')
                        return false;
                    stk.pop();
                    break;
                }
                default: stk.push(i);
            }
        }
        
        return stk.empty() ? true :false;
        
    }
};
