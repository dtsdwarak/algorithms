class Solution {
    
    void performOperation(string &operation, int &x) {
        
        if (operation == "--X" || operation == "X--")
            x--;
        else
            x++;
        
    }
    
    
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int x=0;
        for(string op: operations)
            performOperation(op, x);
        
        return x;
    }
};
