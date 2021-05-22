class Solution {
public:
    
    int firstCharacterOccurrence(unordered_map<char, int> &lastIndexMap) {
        
        int minIndex = INT_MAX;
        
        for(auto i: lastIndexMap)
            minIndex = min(minIndex, i.second);
        
        return minIndex;
    }
    
    string smallestSubsequence(string s) {
        
        unordered_map<char, int> lastIndexMap;
        for(int i=0; i<s.length(); i++) {
            lastIndexMap[s[i]] = i;
        }
        
        int startIndex = 0;
        string ans;
        
        while(!lastIndexMap.empty()) {
            
            int minIndex = firstCharacterOccurrence(lastIndexMap);
            
            char minCharacter = 'z' + 1;
            int minCharacterIndex = INT_MAX;
            
            for(int i=startIndex; i<=minIndex; i++) {
                if (minCharacter > s[i] && lastIndexMap.find(s[i]) != lastIndexMap.end()) {
                    minCharacter = s[i];
                    minCharacterIndex = i;
                }
            }
            
            ans += minCharacter;
            
            lastIndexMap.erase(minCharacter);
            startIndex = minCharacterIndex + 1;
            
        }
        
        return ans;
        
    }
};
