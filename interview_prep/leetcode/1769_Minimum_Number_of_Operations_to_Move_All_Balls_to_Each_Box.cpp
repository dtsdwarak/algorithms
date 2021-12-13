class Solution {
public:
    vector<int> minOperations(string boxes) {
     
        set<int> boxesWithBalls;
        
        for(int i=0; i<boxes.length(); i++) {
            if (boxes[i]=='1')
                boxesWithBalls.insert(i);
        }
        
        vector<int> ans(boxes.length());
        
        for(int i=0;i<boxes.length();i++) {
            
            int count=0;
            
            for(int box:boxesWithBalls)
                count += abs(box - i);
            
            ans[i] = count;
        }
        
        return ans;
    }
};
