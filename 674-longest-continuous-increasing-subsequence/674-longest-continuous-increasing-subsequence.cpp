class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int count = 0;
        int curMax = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] > nums[i-1]) {
                count++;
            } else {
                count = 1;
            }
            
            curMax = max(curMax, count);
        }
        
        return curMax;
    }
};