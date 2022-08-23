class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        
        int curSum = 0;
        int maxNum = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            curSum+= nums[i];
            maxNum = max(maxNum, curSum);
            
            if(curSum < 0) {
                curSum = 0;
            }
        }
        
        return maxNum;
    }
};