class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int smallestDiff = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; i++) {
            int lo = i+1;
            int hi = nums.size() - 1;
            
            while(lo < hi) {
                int diff = target - nums[i] - nums[lo] - nums[hi];
                
                if(diff == 0) {
                    return target - diff;
                }
                
                 if (abs(diff) < abs(smallestDiff)) {
                     smallestDiff = diff;
                 };
                
                if(diff > 0) {
                    lo++;
                } else {
                    hi--;
                }
            }
        }
        
        return target - smallestDiff;

    }
};