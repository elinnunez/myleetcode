class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int smallest_diff = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()-2; i++) {
            int lo = i+1;
            int high = nums.size() -1;
            
            while(lo < high) {
                int diff = target - (nums[i] + nums[lo] + nums[high]);
                
                if(diff == 0) {
                    return target - diff;
                }
                
                if(abs(diff) < abs(smallest_diff)) {
                    smallest_diff = diff;
                }
                
                if(diff > 0) {
                    lo++;
                } else {
                    high--;
                }
            }
        }
        
        return target - smallest_diff;

    }
};