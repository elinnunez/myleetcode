class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if(nums.size() == 1) {
            return nums[0];
        }
        
        int curMax = INT_MIN;
        int curSum = 0;
        
        int i = 0;
        
        while(i < nums.size()) {
            curSum+= nums[i];
            
            curMax = max(curSum, curMax);
            
            if(curSum < 0) {
                curSum = 0;
            }
            
            i++;
        }
        
        return curMax;
    }
};