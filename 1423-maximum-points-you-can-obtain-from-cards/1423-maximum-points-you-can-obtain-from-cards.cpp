class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(); // O(1)
        int left = 0;
        int right = n - k;
        
        int total = 0;
        
        for(int i = right; i < n; i++) { // O(k)
            total+= cardPoints[i];
        }
        
        int result = total;
        
        while(right < n) { // O(k)
            total+= (cardPoints[left] - cardPoints[right]);
            result = max(result, total); // O(1)
            left++;
            right++;
        }
        
        return result;
    }
};

// Time Complexity: O(k)