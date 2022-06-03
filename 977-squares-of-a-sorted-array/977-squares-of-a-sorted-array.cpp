class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> output(nums.size());

        int maxIdx = nums.size() - 1;
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right) {
            int lSquared = pow(nums[left], 2);
            int rSquared = pow(nums[right], 2);
            if(lSquared > rSquared) {
                output[maxIdx] = lSquared;
                left++;
            } else {
                output[maxIdx] = rSquared;
                right--;
            }
            maxIdx--;
        }
        
        return output;
                   
    }
};