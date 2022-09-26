class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        
        int LIS = 0;
        
        for(int i = 0; i < dp.size(); i++) {
            LIS = max(LIS,dp[i]);
        }
        
        return LIS;
    }
};