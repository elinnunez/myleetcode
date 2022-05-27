class Solution {
public:
    int minSubArrayLen(int S, vector<int>& arr) {
        
    int minAmt = INT_MAX;
    int winStart = 0;
    int winSum = 0;
    for(int i = 0; i < arr.size(); i++) {
      if(arr[i] == S) {
        return 1;
      }

      winSum+=arr[i];

      while(winSum >= S) {
        minAmt = min(minAmt, i - winStart+1);
        winSum -= arr[winStart];
        winStart++;
      }
    }
    
    if(minAmt == INT_MAX) {
        return 0;
    }
    return minAmt;
    }
};