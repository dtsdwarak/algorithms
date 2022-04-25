class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        if (strs.size()==0)
            return vector<vector<string>>{vector<string>()};
        
        if (strs.size() == 1)
            return vector<vector<string>>{vector<string>{strs[0]}};
        
        unordered_map<string, vector<string>> stringGroup;
        for(string& s: strs) {
            
            string temp = s;
            sort(temp.begin(), temp.end());
            
            if (stringGroup.count(temp))
                stringGroup[temp].push_back(s);
            else
                stringGroup[temp] = vector<string>{s};
            
        }
        
        vector<vector<string>> ans;
        for(auto& entry : stringGroup)
            ans.push_back(entry.second);
        
        return ans;
        
    }
};
