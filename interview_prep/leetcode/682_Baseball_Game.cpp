class Solution {
public:
    int calPoints(vector<string>& ops) {

        stack<int> s;
        
        for(string c : ops) {
            switch(c[0]) {
                case '+': {
                            int b = s.top(); s.pop();
                            int a = s.top(); s.pop();
                            s.push(a); s.push(b);
                            s.push(a+b);
                            break;
                }
                case 'D': {
                            int x = s.top() * 2;
                            s.push(x);
                            break;
                }
                case 'C':  {
                            s.pop();
                            break;
                }
                default: 
                            s.push(stoi(c));
            }
            
        }
        
        int sum=0;
        while(!s.empty()) {
            sum += s.top();
            s.pop();
        }
        
        return sum;
    }
};
