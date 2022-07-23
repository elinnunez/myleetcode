class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0;
        int right = n - k;
        
        int maxPoints = 0;
        
        for(int i = right; i < n; i++) {
            maxPoints+= cardPoints[i];
        }
        
        int total = maxPoints;
        
        while(right < n) {
            total+= cardPoints[left] - cardPoints[right];
            maxPoints = max(maxPoints, total);
            right++;
            left++;
        }
        
        return maxPoints;
        
    }
};

// Time Complexity: O(n) when all cards are counted