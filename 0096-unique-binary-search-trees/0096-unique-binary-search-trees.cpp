class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 1);
        
        for(int nodes = 2; nodes <= n; nodes++) {
            int total = 0;
            
            for(int root = 1; root <= nodes; root++) {
                int left = root-1;
                int right = nodes-root;
                total+= dp[left]*dp[right];
            }
            
            dp[nodes] = total;
        }
        
        return dp[n];
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)