class Solution {
public:
    int backtrack(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp) {
        if(idx == 0) {
            if(amount % coins[idx] == 0) return amount/coins[idx];
            
            return INT_MAX-1;
        }
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int take = INT_MAX;
        
        if(amount >= coins[idx]) {
            take = 1 + backtrack(coins,amount-coins[idx],idx,dp);
        }
        
        int nottake = backtrack(coins,amount,idx-1,dp);
        
        dp[idx][amount] = min(take,nottake);
        
        return dp[idx][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        
        int res = backtrack(coins,amount,n-1,dp);
        
        if(res == INT_MAX-1) return -1;
        
        return res;
    }
};
// Time Complexity: O(2^n)