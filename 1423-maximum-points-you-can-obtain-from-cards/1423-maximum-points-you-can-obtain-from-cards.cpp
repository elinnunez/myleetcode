class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0;
        int right = n - k;
        
        int total = 0;
        
        for(int i = right; i < n; i++) {
            total+= cardPoints[i];
        }
        
        int result = total;
        
        while(right < n) {
            total+= (cardPoints[left] - cardPoints[right]);
            result = max(result, total);
            left++;
            right++;
        }
        
        return result;
    }
};