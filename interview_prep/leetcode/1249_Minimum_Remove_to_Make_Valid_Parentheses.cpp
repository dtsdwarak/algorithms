class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> indexOfOpenBrackets;
        unordered_set<int> indexesToBeRemoved;
        
        for(int i=0; i<s.length(); i++) {
            if (s[i] == '(') {
                indexOfOpenBrackets.push(i);
            } else if (s[i] == ')') {
                if (!indexOfOpenBrackets.empty())
                    indexOfOpenBrackets.pop();
                else
                    indexesToBeRemoved.insert(i);
            }
        }
        
        string ans;
        
        while(!indexOfOpenBrackets.empty()) {
            indexesToBeRemoved.insert(indexOfOpenBrackets.top());
            indexOfOpenBrackets.pop();
        }
        
        for(int i=0;i<s.length(); i++) {
            if (indexesToBeRemoved.find(i) == indexesToBeRemoved.end())
                ans += s[i];
        }
        
        return ans;
        
    }
};
