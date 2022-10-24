class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-2;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            
            if(nums[mid] == nums[mid^1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return nums[low];
    }
};
// Time Complexity: O(logn)
// Space Complexity: O(1)
// Reference: https://www.youtube.com/watch?v=PzszoiY5XMQ&list=PLgUwDviBIf0qYbL4TBaEWgb-ljVdhkM7R&index=4