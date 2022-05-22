class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        
        int cursum = 0;
        int maxnum = nums[0];
        
        for(int r = 0; r < nums.size(); r++) {
            
            if(cursum < 0) {
                cursum = 0;
            }
            cursum+= nums[r];
            
            maxnum = max(cursum, maxnum);
        }
        
        return maxnum;
    }
};