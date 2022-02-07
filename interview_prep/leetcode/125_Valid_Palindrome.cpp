class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length() -1;
        while( start < end) {
            
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            else if (!isalnum(s[end])) {
                end--;
                continue;
            }
            
            char startChar = (s[start] <= 90 && s[start] >= 65) ? s[start] | ' ' : s[start];
            char endChar = (s[end] <= 90 && s[end] >= 65) ? s[end] | ' ' : s[end];
            
            if (startChar != endChar)
                return false;
            start++;
            end--;
        }
        return true;
    }
};
