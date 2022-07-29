class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        
        int curSum = 0;
        int left = 0;
        for(int right = 0; right < arr.size(); right++) {
            curSum+= arr[right];
            
            if(right-left +1 == k) {
                int avg = curSum / k;
                
                if(avg >= threshold) {
                    count++;
                }
                curSum -= arr[left];
                left++;
            }
        }
        
        return count;
    }
};