class Solution {

public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() < 2)
            return 0;

        int i=0, valley = prices[0], peak = prices[0], maxProfit =0;

        while (i < prices.size() -1) {
            
            while (i<prices.size()-1 && prices[i] >= prices[i+1])
            i++;

            valley = prices[i];

            while (i<prices.size()-1 && prices[i] <= prices[i+1])
            i++;

            peak = prices[i];

            maxProfit += peak - valley;
        }

        return maxProfit;

    }
};
