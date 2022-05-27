class Solution {
public:
    int minSubArrayLen(int S, vector<int>& arr) {
        
        int minAmt = INT_MAX; // initialize at max int
        int winStart = 0; // set left at 0 index of array
        int winSum = 0; // keep track of sum while looking for smallest contiguous array
    
        for(int i = 0; i < arr.size(); i++) {
          if(arr[i] == S) { // if val == S then 1 is the smallest arr possible
            return 1;
          }

          winSum+=arr[i]; // add value to winSum

          while(winSum >= S) { // loop while winSum is greater than S
            minAmt = min(minAmt, i - winStart+1); // get minimum as left side shrinks window
            winSum -= arr[winStart]; // subtract from leftside value
            winStart++; // keep incrementing until winSum is < S
          }
        }

        // if there were no changes than an array couldnt be found so return 0 else return minAmt
        return minAmt == INT_MAX ? 0 : minAmt;
    }
};

// Two Pointer / Sliding Window