class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        
        int l=1, r=*max_element(piles.begin(), piles.end()), mid;
        
        while(l < r) {
            
            mid = l + (r-l)/2;
            int totalHours = 0;
            
            for(auto pile : piles)
                totalHours += (pile + mid -1)/mid;
            
            if (totalHours > h)
                l = mid +1;
            else
                r = mid;
        }
        
        return l;
        
    }
};
