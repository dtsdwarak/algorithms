class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 1) {
            return strs[0];
        }

        string prefix = strs[0];
        for(auto i =1; i<strs.size(); i++) {
            
            int k=0;
            string word = strs[i];

            while(k < prefix.size() && k < word.size() && (prefix[k] == word[k])) {
                k++;
            }

            if (k==0) {
                return "";
            }
            else if (k == word.size())
                prefix = word;
            else if (k < prefix.size())
                prefix = word.substr(0,k);
        }

        return prefix;
    }
};
