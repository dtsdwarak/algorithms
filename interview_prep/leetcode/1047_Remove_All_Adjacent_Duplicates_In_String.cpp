class Solution {
public:
    string removeDuplicates(string S) {
        
        stack<char> s;
        string ans;
        
        for(char i: S) {
            if (!s.empty() && s.top() == i)
                s.pop();
            else
                s.push(i);
        }
        
        while(!s.empty()) {
            ans = s.top() + ans;
            s.pop();
        }
        
        return ans;
    }
};
