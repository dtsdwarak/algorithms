class Solution {
public:
    bool isPalindrome(int x) {
        
        string num = to_string(x);
        int n = num.length();

        for(int i=0; i<n/2; i++) {
            if (num[i] != num[n-i-1])
                return false;
        }
        return true;
    }
};
