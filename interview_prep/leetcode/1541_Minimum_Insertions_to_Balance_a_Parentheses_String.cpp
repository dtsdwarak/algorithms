class Solution {
public:
    int minInsertions(string s) {
        
        stack<char> stk;
        
        for(char i : s) {
            
            if (stk.empty())
                stk.push(i);
            else {
                
                if (stk.top() == ')' && i == '(') {
                    stk.pop();
                    stk.push('i');
                    stk.push('(');
                }
                else if (stk.top() == ')' && i == ')' ) {
                    stk.pop();
                    stk.push('c');
                }
                else {
                    stk.push(i);
                }
                
            }
        }
        
        if (stk.top() == ')') {
            stk.pop();
            stk.push('i');
        }
        
        stack<char> stk2;
        
        while(!stk.empty()) {
            stk2.push(stk.top());
            stk.pop();
        }
        
        int sum = 0;
        
        while(!stk2.empty()) {
            
            if (stk.empty()) {
                stk.push(stk2.top());
                stk2.pop();
            }
            else {
                
                if (stk.top() == '(' && stk2.top() == 'c') {
                    stk.pop();
                    stk2.pop();
                }
                else if (stk.top() == '(' && stk2.top() == 'i') {
                    sum += 1;
                    stk.pop();
                    stk2.pop();
                }                
                else {
                    stk.push(stk2.top());
                    stk2.pop();
                }                
            }
            
        }
        
        
        while(!stk.empty()) {
            
            switch(stk.top()) {
                case '(' : {
                    sum += 2;
                    break;
                }
                case 'i' : {
                    sum += 2;
                    break;
                }
                case 'c' : {
                    sum += 1;
                    break;
                }
            }
            
            stk.pop();
            
        }
        
        return sum;
        
        
        
        
        
    }
};
