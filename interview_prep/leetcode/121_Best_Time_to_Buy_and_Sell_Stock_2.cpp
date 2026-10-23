class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min_cp = prices[0];
        int max_sp = prices[0];
        int best_profit = max_sp-min_cp;

        for(int i=1; i<prices.size(); i++) {
            
            if (prices[i] < min_cp) {
                min_cp = prices[i];
                max_sp = prices[i];
            }
            else if (prices[i] > max_sp) {
                max_sp = prices[i];
                best_profit = max(best_profit, max_sp-min_cp);
            }

        }

        return best_profit;

    }
};
