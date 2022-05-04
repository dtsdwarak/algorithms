class Solution {
    
public:
    bool checkInclusion(string s1, string s2) {
        
        if (s1.length() > s2.length())
            return false;
        
        vector<int> s1Map(26, 0), s2Map(26, 0);
        
        for(int i=0; i<s1.length(); i++) {
            s1Map[s1[i]-'a']++;
            s2Map[s2[i]-'a']++;
        }
        
        if (s1Map == s2Map)
            return true;
        
        for(int i=s1.length(); i<s2.length(); i++) {
            s2Map[s2[i-s1.length()]-'a']--;
            s2Map[s2[i]-'a']++;
            if (s1Map == s2Map)
                return true;
        }
        
        return false;
        
    }
};
