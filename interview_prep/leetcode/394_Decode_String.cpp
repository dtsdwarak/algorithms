class Solution {
public:
    string decodeString(string s) {
        
        stack<char> stk;
        
        for(char i: s) {
            
            if (i == ']') {
                
                string toRepeat = "", repeat;
                
                while(stk.top() != '[') {
                    toRepeat = stk.top() + toRepeat;
                    stk.pop();
                }
                stk.pop();
                
                string countStr = "";
                while (!stk.empty() && stk.top() >= '0' && stk.top() <= '9') {
                    countStr = stk.top() + countStr;
                    stk.pop();
                }
                
                int count = stoi(countStr);
                
                while(count--)
                    repeat += toRepeat;
                
                for(char j: repeat)
                    stk.push(j);
            }
            
            else
                stk.push(i);
        }
        
        string ans = "";
        while(!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        
        return ans;
        
    }
};
