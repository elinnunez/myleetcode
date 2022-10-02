class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            
            int pick = nums[i] + prev2;
            int notpick = prev;
            
            prev2 = prev;
            
            prev = max(pick,notpick);

        }

        return prev;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)