class Solution {

    unordered_set<int> elements;
    
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i: nums) {
            
            if (elements.count(i))
                return i;
            elements.insert(i);
        }
        
        // Default staement
        return 0;
        
    }
};
