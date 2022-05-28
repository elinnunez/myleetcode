class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int left = 0;
        int maxCount = 0;
        int zeroCount = 0;
        
        for(int r = 0; r < nums.size(); r++) {
            int curInt = nums[r];
            
            if(curInt == 0) {
                zeroCount++;
            }
            
            while(zeroCount > k) {
                if(nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            maxCount = max(maxCount, r - left + 1);
        }
        
        return maxCount;
        
    }
};