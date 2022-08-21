class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) {
            return 0;
        }
        
        int left = 0;
        int right = 0;
        
        int count = 0;
        int product = 1;
        
        while(right < nums.size()) {
            product*=nums[right];

            if(product < k) {
                count+= (right-left+1);
            } else {
                while(product >= k) {
                    product/=nums[left];
                    left++;
                }
                count+= (right-left+1);
            }
            right++;
        }
        
        return count;
        
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1);
