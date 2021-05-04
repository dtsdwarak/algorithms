class CustomStack {
public:
    
    int size;
    vector<int> stk;
    
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if (stk.size() < size)
            stk.push_back(x);
    }
    
    int pop() {
        if (stk.empty())
            return -1;
        int x = stk[stk.size()-1];
        stk.erase(stk.end() - 1); //stk.pop_back() will work too
        return x;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k && i<stk.size();i++)
            stk[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
