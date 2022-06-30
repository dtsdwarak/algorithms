/*
* Explanation - 
* https://www.youtube.com/watch?v=gVUrDV4tZfY
* https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary%3A-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently
*/
class Solution {
public:
    int getSum(int a, int b) {
        
        if (b==0)
            return a;
        
        // Why unsigned int? https://leetcode.com/problems/sum-of-two-integers/discuss/302977/C++:-the-evil-runtime-error:-left-shift-of-negative-value-reason-and-how-to-solve
        return getSum(a^b, (unsigned int)(a&b)<<1);
        
    }
};
