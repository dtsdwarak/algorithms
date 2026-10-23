class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int candidate;
        int count = 0;

        for(auto& num: nums) {
            
            if (count==0) {
                candidate = num;
                count++;
                continue;
            }
            
            if (candidate != num) {
                count--;
            } else {
                count++;
            }

        }

        return candidate;

    }
};
