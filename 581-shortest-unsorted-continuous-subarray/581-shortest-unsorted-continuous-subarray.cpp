class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int left = 0;
        
        int right = n - 1;
        
        // find the index where sorted condition is violated from both start and end
        
        while(left + 1 < n && nums[left] <= nums[left+ 1])
            left++;
        
        while(right > 0 && nums[right] >= nums[right - 1])
            right--;
        
        // if array is already sorted
        
        if(left >= n - 1)
            return 0;
        
        // find the maximum and minimum element between violated index (i <= k <= j)
        
        int maxi = INT_MIN;
        
        int mini = INT_MAX;
        
        for(int k = left; k <= right; k++)
        {
            maxi = max(maxi, nums[k]);
            
            mini = min(mini, nums[k]);
        }
      
        int start = 0;
        
        int end = n - 1;
        
        // now find the first index from start where the element is not in correct position
        
        while(start <= left && nums[start] <= mini)
            start++;
        
        // find the last index from end where the element is not in correct position
        
        while(end >= right && nums[end] >= maxi)
            end--;
        
        return end - start + 1;
    }
};