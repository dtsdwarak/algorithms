class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        multiset<int> s1(nums.begin(),nums.end());
        
        int start=0;
        
        for(auto &i: s1) {
            if (i != nums[start])
                break;
            start++;
        }
        
        int end = nums.size()-1;
        
        if (start >= end)
            return 0;
        
        // cout<<"start ="<<start<<endl;
        
        for(auto i  = s1.rbegin(); i != s1.rend(); i++) {
            if (*i != nums[end])
                break;
            end--;
        }
        
        // cout<<"end = "<<end<<endl;
        
        return end-start+1;
        
        
    }
};



/*

2 6 4 8 10  9 15
2 6 8 4 10  9 15
2 4 6 8  9 10 15
 

*/
