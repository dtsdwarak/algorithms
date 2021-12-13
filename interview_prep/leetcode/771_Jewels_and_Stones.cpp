class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        set<char> jewelSet;
        
        for(char c:jewels)
            jewelSet.insert(c);
        
        int count=0;
        
        for(char c: stones) {
            if (jewelSet.count(c) != 0)
                count++;
        }
        
        return count;
    }
};
