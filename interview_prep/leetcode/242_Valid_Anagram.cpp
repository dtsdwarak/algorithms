class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.length() != t.length())
            return false;
        
        unordered_map<char, int> charMap;
        
        for(int i=0; i<s.length(); i++) {
            charMap[s[i]]++;
            charMap[t[i]]--;
        }
        
        for(auto entry : charMap) {
            if (entry.second)
                return false;
        }
        
        return true;
        
    }
};
