class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> stk;
        
        int push = 0, pop =0;
        
        while(push != pushed.size() && pop != popped.size()) {
            
            while (push != pushed.size() && (stk.empty() || stk.top() != popped[pop])) {
                stk.push(pushed[push]);
                push++;
            }
            
            while(pop != popped.size() && !stk.empty() && stk.top() == popped[pop]) {
                stk.pop();
                pop++;
            }
            
        }
        
        while(pop != popped.size() && !stk.empty() && stk.top() == popped[pop]) {
            stk.pop();
            pop++;
        }
        
        return pop == popped.size() ? true : false;
        
    }
};

