class StockSpanner {
public:
    
    vector<int> s;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int span=1;
        for(int i=s.size()-1; i>-1 && s[i] <= price; i--)
            span++;
        s.push_back(price);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
