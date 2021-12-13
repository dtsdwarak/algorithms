class Solution {
public:
    int maxPower(string s) {
        
        int power = 1, localMax = 1;
        
        for(int i=0; i<s.length()-1; i++) {
            if (s[i] == s[i+1]) {
                localMax++;
                power = max(power, localMax);
            }
            else
                localMax=1;
        }
        
        return power;
        
    }
};
