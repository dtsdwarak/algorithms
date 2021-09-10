class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        
        vector<vector<int> > ans;
        ans.push_back(vector<int>{1});
        
        if (numRows == 1)
            return ans;
        
        ans.push_back(vector<int>{1,1});
        
        if (numRows == 2)
            return ans;
        
        numRows -= 2;
        
        while(numRows--) {
            
            vector<int> prev = ans.back();
            vector<int> current;
            current.push_back(1);
            
            for(int i=0; i<prev.size()-1; i++)
                current.push_back(prev[i]+prev[i+1]);
            
            current.push_back(1);
            ans.push_back(current);
        }
        
        return ans;
        
    }
};
