class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int> > elements;
    int n;
    
    KthLargest(int k, vector<int>& nums) {
        
        n = k;
        
        for(int i: nums)
            elements.push(i);
        
    }
    
    int add(int val) {
        
        elements.push(val);
        
        while(elements.size() != n)
            elements.pop();
        
        return elements.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
