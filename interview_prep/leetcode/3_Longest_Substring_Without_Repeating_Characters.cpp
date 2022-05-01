class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> characterIndexMap;
        int windowStart=0, sizeOfLongestSubstring = 0;
        
        
        for(int i=0; i<s.length(); i++) {
            
            if (characterIndexMap.find(s[i]) != characterIndexMap.end())
                windowStart = max(windowStart, characterIndexMap[s[i]] + 1); //For usecase like "abba"
            
            characterIndexMap[s[i]] = i;
            sizeOfLongestSubstring = max(sizeOfLongestSubstring, i - windowStart +1);
        }
        
        return sizeOfLongestSubstring;
        
    }
};
