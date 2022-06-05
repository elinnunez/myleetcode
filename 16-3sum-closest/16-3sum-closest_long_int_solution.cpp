class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        long int smallestSum = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; i++) {
            int lo = i+1;
            int hi = nums.size() - 1;
            
            while(lo < hi) {
                int curSum = nums[i] + nums[lo] + nums[hi];
                
                if(curSum < target) {
                    lo++;
                } else {
                    hi--;
                }
                if(abs(curSum - target) < abs(smallestSum - target)) {
                    smallestSum = curSum;
                }
            }
        }
        
        return smallestSum;

    }
};
