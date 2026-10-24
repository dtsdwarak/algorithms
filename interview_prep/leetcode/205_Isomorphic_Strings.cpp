class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> sToTmap_; // s[i] -> t[i]
        unordered_map<char, char> tToSmap_; // t[i] -> s[i]

        for(int i=0; i<s.length(); i++) {
            if (sToTmap_.count(s[i]) && !tToSmap_.count(t[i])) {
                return false;
            }
            if (!sToTmap_.count(s[i]) && tToSmap_.count(t[i])) {
                return false;
            }
            if (sToTmap_.count(s[i]) && tToSmap_.count(t[i])) {
                if (sToTmap_[s[i]] != t[i] || tToSmap_[t[i]] != s[i])
                    return false;
            }
            else {
                sToTmap_[s[i]] = t[i];
                tToSmap_[t[i]] = s[i];
            }    
        }

        return true;
    }
};
