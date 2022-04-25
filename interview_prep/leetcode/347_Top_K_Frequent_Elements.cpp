class Solution {
    
    static bool pairCompare(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     
        unordered_map<int, int> numberFrequencyMap;
        
        for(int &i : nums)
            numberFrequencyMap[i]++;
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> numFrequencyHeap(pairCompare);
        
        for(auto& entry : numberFrequencyMap)
            numFrequencyHeap.push(entry);
        
        vector<int> ans;
        
        while(k) {
            ans.push_back(numFrequencyHeap.top().first);
            numFrequencyHeap.pop();
            k--;
        }
        
        return ans;
        
    }
};
