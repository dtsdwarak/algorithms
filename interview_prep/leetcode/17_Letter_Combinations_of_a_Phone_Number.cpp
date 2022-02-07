class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if (digits.size() == 0)
            return vector<string>();
        
        
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> result = {""};
        
        for(char i: digits) {
            
            vector<string> tmp;
            
            for(auto j: pad[i-'0']) {
                
                for(auto k: result)
                    
                    tmp.push_back(k+j);
                
            }
            
            result = tmp;
            
        }
        
        return result;
        
    }
};
