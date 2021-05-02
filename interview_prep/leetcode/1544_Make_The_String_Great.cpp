class Solution {
public:
    
    string makeGood(string s) {
        
        if (s.size() == 1)
            return s;
        
        string ans;
        stack<char> stk;
        
        for(char i: s) {
            if (!stk.empty() && abs(stk.top() - i) == 32)
                stk.pop();
            else
                stk.push(i);
        }
        
        while(!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        
        return ans;
        
    }
};
