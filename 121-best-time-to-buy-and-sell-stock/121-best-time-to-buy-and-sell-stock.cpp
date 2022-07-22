class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l,r,maxProfit;
        l = r = maxProfit = 0;
        
        while(r < prices.size()) {
            if(prices[l] < prices[r]) {
                int profit  = prices[r] - prices[l];
                maxProfit = max(maxProfit, profit);
            } else {
                l = r;
            }
            r++;
        }
        
        return maxProfit;
    
    }
};