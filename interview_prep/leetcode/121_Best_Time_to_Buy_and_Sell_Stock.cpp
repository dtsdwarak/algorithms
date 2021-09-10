class Solution {
    
    int minStockPrice = INT_MAX, maxStockPrice = -1, bestProfit = 0;
    
    
public:
    int maxProfit(vector<int>& prices) {
        for(int i : prices) {
            
            if (i < minStockPrice) {
                minStockPrice = i;
                maxStockPrice = -1;
            }
            else if (i > maxStockPrice) {
                maxStockPrice = i;
                bestProfit = max(maxStockPrice-minStockPrice, bestProfit);
            }
            
        }
        
        return bestProfit;
    }
};
