class Solution {
public:
    string removeOuterParentheses(string S) {
        
        string answer="";
        int count = 0;
        
        for(char i : S) {
            
            if (i == '(' && count++ > 0)
                answer += i;
            
            if (i == ')' && --count > 0)
                answer += i;
        }
        
        return answer;
        
    }
};
