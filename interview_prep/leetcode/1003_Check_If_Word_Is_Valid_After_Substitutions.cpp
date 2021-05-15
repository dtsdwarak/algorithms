class Solution {
public:
    bool isValid(string s) {
        
        vector<char> processedString;
        
        for(int i=0; i<s.length(); i++) {
            
            if (processedString.size() > 1 && s[i] == 'c') {
                
                int n = processedString.size() - 1;
                
                if (processedString[n] == 'b' && processedString[n-1] == 'a')
                    processedString.resize(processedString.size() - 2);
                else
                    processedString.push_back(s[i]);
            }
            
            else
                processedString.push_back(s[i]);
            
        }
        
        return processedString.empty() ? true : false;
        
    }
};
