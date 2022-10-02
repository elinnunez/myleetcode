class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0; // currently out of bounds thus 0 value aka (at -1 index)
        int prev = nums[0]; // 0th index is our current max adj. sum
        
        for(int i = 1; i < nums.size(); i++) {
            
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