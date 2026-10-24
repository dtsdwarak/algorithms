class Solution {

    bool subsetSum(vector<int>&arr, int val) {

        int n = arr.size() -1;
        vector<vector<bool>> t(n+1, vector<bool>(val+1, false));
        
        // Initialization
        for(int j=0; j<val+1; j++) {
            t[0][j] = false;
        }
        for(int i=0; i<n+1; i++) {
            t[i][0]=true;
        }

        for(int i=1; i<n+1; i++) {
            for(int j=1; j<val+1; j++) {
                
                if (arr[i-1] <= j) 
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }

        return t[n][val];

    }

public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int& n: nums) {
            sum += n;
        }

        if (sum & 1)
            return false;

        return subsetSum(nums, sum/2);

    }
};
