class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        set<int> s;
        for(int &i: nums)
            s.insert(i);
  
        if (s.size()<3)
            return *prev(s.end());
        
        auto p = s.end(); 
        advance(p, -3);
        return *p;
        
    }
};
