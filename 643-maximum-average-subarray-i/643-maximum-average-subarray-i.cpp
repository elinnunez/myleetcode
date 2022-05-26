class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double maxAvg = INT_MIN;
        
        int windowStart = 0;
        double windowSum = 0;
        
        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            
            windowSum+= nums[windowEnd];
            
            if(windowEnd >= k-1) {
                double curAvg = windowSum/k;
                maxAvg = max(curAvg, maxAvg);
                windowSum -= nums[windowStart];
                windowStart++;
            }
        }
        
        return maxAvg;
        
    }
};