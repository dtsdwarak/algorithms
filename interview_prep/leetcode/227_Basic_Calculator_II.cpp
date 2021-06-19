class Solution {
public:
void calculateMulDiv(string &num, stack<string> &stk) {

  if (num != "") {
      
      if (!stk.empty() && (stk.top() == "/" || stk.top() == "*")) {
          
          string operater = stk.top();
          stk.pop();
          
          int secondOperand = stoi(num);
          int firstOperand = stoi(stk.top()); stk.pop();
          
          if (secondOperand == 0)
              num = "0";
          else if (operater == "/")
              num = to_string(firstOperand / secondOperand);
          else
              num = to_string(firstOperand * secondOperand);
          }
      
      stk.push(num);
      num = "";
      
      }

}


int calculate(string s) {
    
    
    stack<string> stk;
    string num;
    
    for(int i=0; i<s.size(); i++) {
        
        if (s[i] >= '0' && s[i] <= '9')
            num += s[i];
        else {
            
            calculateMulDiv(num, stk);
            if (s[i] == ' ')
                continue;
            else
                stk.push(string(1,s[i]));
        }
    }
    
    calculateMulDiv(num, stk);
    
    int ans = 0;
    
    int number=0;
    
    while(!stk.empty()) {
        
        if (stk.top() == "-")
            number *= -1;
        else if (stk.top() != "+") {
            ans += number;
            number = stoi(stk.top());
        }
        
        stk.pop();
        
    }
    
    ans += number;
    
    return ans;
    
    }

};
