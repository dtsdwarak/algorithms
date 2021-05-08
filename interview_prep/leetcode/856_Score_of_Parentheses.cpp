/*
* References -
* 1. https://www.youtube.com/watch?v=Pv35fyoKtUA
* 2. https://www.geeksforgeeks.org/calculate-score-of-a-string-consisting-of-balanced-parentheses/
*/

class Solution {
public:
    int scoreOfParentheses(string S) {
     
        stack<int> stk;
        
        for(char i: S) {
            
            if (i == '(')
                stk.push(0);
            else {
                int sum = 0;
                while(!stk.empty() && stk.top() != 0) {
                    sum += stk.top();
                    stk.pop();
                }
                stk.pop();
                stk.push(max(2*sum, 1));
            }
        }
        
        int sum=0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        
        return sum;
        
    }
};
