class Solution {
    public int maxSubArray(int[] nums) {
        
        if(nums.length == 1) {
            return nums[0];
        }
        
        int cursum = 0;
        int maxnum = nums[0];
        
        for(int i = 0; i < nums.length; i++) {
            if(cursum < 0) {
                cursum = 0;
            }
            cursum+= nums[i];
            maxnum = Math.max(cursum,maxnum);
        }
        
        return maxnum;
        
    }
}