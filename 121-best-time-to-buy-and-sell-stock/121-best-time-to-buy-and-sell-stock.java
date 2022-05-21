class Solution {
    public int maxProfit(int[] prices) {
        int l, r, maxP;
        l = 0;
        r = 0;
        maxP = 0;
        
        while(r < prices.length) {
            if(prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxP = Math.max(maxP, profit);
            } else {
                l = r;
            }
            r++;
        }
        
        return maxP;
        
    }
}