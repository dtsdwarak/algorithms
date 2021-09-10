class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans=vector<int>{1};
        
        if (rowIndex == 0)
            return ans;
        
        ans=vector<int>{1,1};
        
        if (rowIndex == 1)
            return ans;
        
        rowIndex -= 2;
        
        while(rowIndex-- > -1) {
            
            vector<int> current;
            current.push_back(1);
            
            for(int i=0; i<ans.size()-1;i++)
                current.push_back(ans[i]+ans[i+1]);
            
            current.push_back(1);
            ans = current;
        }
        
        return ans;
        
    }
};
