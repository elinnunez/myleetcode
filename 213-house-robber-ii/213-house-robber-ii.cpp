class Solution {
public:
    int getMax(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        
        dp[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            int take = nums[i];
            if(i>1) take+= dp[i-2];
            
            int nottake = dp[i-1];
            
            dp[i] = max(take,nottake);
        }
        
        return dp[nums.size()-1];
    }
    
    int rob(vector<int>& nums) {
        vector<int> part1;
        vector<int> part2;
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(i != 0) part1.push_back(nums[i]); // array with first index value omitted
            if(i != n-1) part2.push_back(nums[i]); // array with last index value omitted
        }
        
        if(nums.size() == 1) {
            return nums[0];
        }
        
        return max(getMax(part1),getMax(part2));
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)