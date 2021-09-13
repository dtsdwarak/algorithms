class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> vec;
        unordered_map<int, int> umap;
        
        for(int i=0; i<numbers.size();i++) {
            
            if (umap.count(target-numbers[i])) {
                vec.push_back(umap[target-numbers[i]]+1);
                vec.push_back(i+1);
            }
            else {
                umap.insert({numbers[i], i});
            }
        }
        
        return vec;
        
    }
};
