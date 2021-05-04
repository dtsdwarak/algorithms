class Solution {
public:
    
    string processString(string s) {
        
        stack<char> stk;
        
        for(char i: s) {
            if (i == '#') {
                if (!stk.empty())
                    stk.pop();
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
    
    bool backspaceCompare(string s, string t) {
        
        if (processString(s) == processString(t))
            return true;
        return false;
        
    }
};
