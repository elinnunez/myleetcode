class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0;
        int right = n - k;
        
        int result = 0;
        
        for(int i = right; i < n; i++) {
            result+= cardPoints[i];
        }
        
        int total = result;
        
        while(right < n) {
            total+= (cardPoints[left] - cardPoints[right]);
            result = max(result, total);
            left++;
            right++;
        }
        
        return result;
    }
};

// Time Complexity: O(n) when all cards are counted