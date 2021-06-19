class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        
        for(string i: tokens) {
            
            if (i.length() == 1 && (i[0] < '0' || i[0] > '9')) {
            
                int second = s.top(); s.pop();
                int first = s.top(); s.pop();

                switch(i[0]) {
                    case '/': s.push(first/second); break;
                    case '*': s.push(first*second); break;
                    case '+': s.push(first+second); break;
                    case '-': s.push(first-second); break;
                }

            }
            else
                s.push(stoi(i));
            
        }
        
        return s.top();
        
    }
};
