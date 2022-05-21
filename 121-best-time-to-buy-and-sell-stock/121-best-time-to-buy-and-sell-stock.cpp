class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = 0;
        
        if(prices.size() == 1) {
            return maxProfit;
        }
        
        int curI = 0;
        int nextDayI = 1;
        
        while(nextDayI < prices.size()) {
            
            maxProfit = max(maxProfit, prices[nextDayI]-prices[curI]);
            
            if(prices[nextDayI] <= prices[curI]) {
                curI = nextDayI;
            }
            nextDayI++;
        }
        
        return maxProfit;
           
    }
};