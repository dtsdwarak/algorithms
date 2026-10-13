class Solution {
public:

    vector<int> computeLPS(string& pattern) {
        
        vector<int> lps(pattern.length());
        lps[0] = 0;
        int i=1, j=0;

        while(i < pattern.length()) {
            if (pattern[i] == pattern[j]) {
                lps[i] = ++j;
                i++;
            }
            else {
                if (j!=0)
                    j = lps[j-1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }
 
    int strStr(string haystack, string needle) {
        
        vector<int> lps = computeLPS(needle);
        int i=0, j=0;

        while(i < haystack.length()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j!=0)
                    j = lps[j-1];
                else
                    i++;
            }

            if (j == needle.length())
                return i-j;
        }

        return -1;

    }
};
