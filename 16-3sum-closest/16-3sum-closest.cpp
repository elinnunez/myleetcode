class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int smallest_diff = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++) {
            int left = i+1;
            int right = nums.size()-1;
            
            while(left < right) {
                int diff = target - (nums[i] + nums[left] + nums[right]);
                
                if(diff == 0) {
                    return target - diff;
                }
                
                if(abs(diff) < abs(smallest_diff)) {
                    smallest_diff = diff;
                }
                
                if(diff > 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return target - smallest_diff;
        
    }
};