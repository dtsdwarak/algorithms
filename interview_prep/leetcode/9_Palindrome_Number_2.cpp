class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0)
            return false;

        if (x < 10)
            return true;

        long long backup = x, reversed =0;
        while(x) {

            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;

        }

        return (backup == reversed);

    }
};
