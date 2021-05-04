class Solution {
public:
    int minAddToMakeValid(string S) {
        
        stack<char> stk;
        int misMatchedParanthesis = 0;
        
        for(char i: S) {
            if (i == ')') {
                if (stk.empty() || stk.top() != '(')
                    misMatchedParanthesis++;
                else
                    stk.pop();
            }
            else
                stk.push(i);
        }
        return misMatchedParanthesis + stk.size();
    }
};
