class Solution {
public:
    int minPartitions(string n) {
        
        int minPartitions = INT_MIN;
        
        for(char c: n)
            minPartitions = max(minPartitions, (int)(c-'0'));
    
        return minPartitions;    
    }
};
