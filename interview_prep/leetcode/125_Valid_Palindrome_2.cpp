class Solution {
public:
    bool isPalindrome(string s) {
        
        string parsedString = "";
        
        for(char& i: s) {
            if (isalnum(i)) 
                parsedString += isdigit(i) ? i : tolower(i);
        }
        
        int n = parsedString.length();
        for(int i=0; i<n/2; i++) {
            if (parsedString[i] != parsedString[n-1-i])
                return false;
        } 
        
        return true;
        
    }
};
