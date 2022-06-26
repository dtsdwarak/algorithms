class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> minStack;
    stack<int> s;
    
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if (minStack.empty())
            minStack.push(val);
        else {
            if (minStack.top() >= val)
                minStack.push(val);
        }
            
    }
    
    void pop() {
        int x = s.top();
        s.pop();
        if (x <= minStack.top())
            minStack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
