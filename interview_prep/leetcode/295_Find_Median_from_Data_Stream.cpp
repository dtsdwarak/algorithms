class MedianFinder {
    
    priority_queue<long> small, large;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        small.push(num); // To keep track of max of smallest bucket
        large.push(-small.top()); // To keep track of min or largest bucket
        small.pop();
        
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
        
    }
    
    double findMedian() {
        
        if (small.size() > large.size())
            return small.top();
        else
            return (double) (small.top() - large.top())/2;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
