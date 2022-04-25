class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        multiset<int> ms(nums.begin(), nums.end());
        int maxStreak=INT_MIN, streak=0;
        int prevElement = INT_MIN;
        
        for(int i : ms) {
            
            cout<<i<<" ";
            
            if (prevElement == INT_MIN)
                streak++;
            else if (i == prevElement) {
                // do nothing
            }
            else if (i-prevElement == 1)
                streak++;
            else {
                maxStreak = max(maxStreak, streak);
                streak = 1;
            }
            prevElement = i;           
        }
        
        maxStreak = max(maxStreak, streak);
        return maxStreak;
        
    }
};


