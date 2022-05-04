class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        multiset<int> ms;
        int count=0;
        
        for(int i : nums) {
            
            if (ms.count(k-i)) {
                auto itr = ms.find(k-i);
                if (itr != ms.end())
                    ms.erase(itr);
                count++;
            }
            else
                ms.insert(i);
        }
        return count;
    }
};
