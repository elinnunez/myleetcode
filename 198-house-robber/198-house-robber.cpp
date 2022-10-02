class Solution {
public:
    int bt(vector<int>& nums, int i,vector<int>& dp) {
        if(i == 0) return nums[i];
        
        if(dp[i] != -1) {
            return dp[i];
        }
        
        int pick = nums[i];
        if(i > 1) {
            pick += bt(nums,i-2,dp);
        }
        int notpick = 0 + bt(nums,i-1,dp);
        
        dp[i] = max(pick,notpick);
        
        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(nums.size(),-1);
        
        return bt(nums,n-1,dp);
    }
};