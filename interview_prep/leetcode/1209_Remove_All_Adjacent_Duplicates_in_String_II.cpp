class Solution {
public:
    
    string removeDuplicates(string s, int k) {
        
        vector<pair<char, int> > processedString;
        
        for(int i=0; i<s.length();i++) {
                
            if (!processedString.empty() && s[i] == processedString.back().first) {
                if (processedString.back().second == k-1) {
                    processedString.resize(processedString.size() - k +1);
                } 
                else {
                    processedString.push_back(make_pair(s[i], processedString.back().second + 1));
                }
            } else {
                processedString.push_back(make_pair(s[i], 1));
            }
            
        }
        
        string ans;
        
        for(auto i : processedString) {
            ans += i.first;
        }
        
        return ans;
        
    }
};
