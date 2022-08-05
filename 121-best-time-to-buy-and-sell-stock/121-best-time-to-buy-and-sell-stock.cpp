class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxP = 0;
        
        int left = 0;
        int right = 0;
        
        while(right < prices.size()) {
            if(prices[right] > prices[left]) {
                int curP = prices[right] - prices[left];
                maxP = max(maxP,curP);
            } else {
                left = right;
            }
            right++;
        }
        
        return maxP;
        
    }
};