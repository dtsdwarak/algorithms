class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> trustors[n+1];
        vector<int> trustee[n+1];
        
        for(auto i: trust) {
            trustors[i[1]].push_back(i[0]);
            trustee[i[0]].push_back(i[1]);
        }
        
        for(int i=1; i<=n; i++) {
            if (trustors[i].size() != n-1)
                continue;
            else {
                int sum = n*(n+1)/2;
                for(int j : trustors[i])
                    sum -= j;
                if (sum == i && trustee[sum].size() == 0)
                    return sum;
            }
        }
        
        return -1;
        
    }
};
