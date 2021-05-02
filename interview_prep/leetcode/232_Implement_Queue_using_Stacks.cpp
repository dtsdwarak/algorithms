class MyQueue {
public:
    
    stack<int> input;
    stack<int> output;
    
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    int getOutputTop() {
        int x = output.top();
        output.pop();
        return x; 
    }
    
    void moveElementsFromInputToOutput() {
        while(!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!output.empty()) {
            return getOutputTop();
        }
        moveElementsFromInputToOutput();
        return getOutputTop();   
    }
    
    /** Get the front element. */
    int peek() {
        if (output.empty()) 
            moveElementsFromInputToOutput();
        return output.top();    
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

