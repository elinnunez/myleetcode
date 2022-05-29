class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r) {
            int mid = l+(r-l)/2; // correct way to not get overflow errors
            if(nums[mid] == target) {
                return mid;
            } else {
                if(nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }   
            }
        }
        
        return -1;
        
    }
};