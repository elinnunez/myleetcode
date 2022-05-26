class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double maxAvg = INT_MIN; // set max sum average to the lowest int possible
        
        int windowStart = 0; // to keep track of which index to delete from sum
        double windowSum = 0; // to sum up the numbers
        
        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            
            windowSum+= nums[windowEnd];
            
            if(windowEnd >= k-1) { // if reached k amount start doing work
                double curAvg = windowSum/k; // calculate average sum
                maxAvg = max(curAvg, maxAvg); // compare to current average vs max average to get the max from both
                windowSum -= nums[windowStart]; // subtract from left side of window
                windowStart++; // increment counter by 1 for next time when index needs to be subtracted
            }
        }
        
        return maxAvg;
        
    }
};

// Sliding Window