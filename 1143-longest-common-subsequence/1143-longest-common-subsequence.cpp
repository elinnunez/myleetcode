class Solution {
public:
//     int backtrack(string t1, string t2, int idx1, int idx2, vector<vector<int>>& dp) {
//         if(idx1 < 0 || idx2 < 0) return 0;
        
//         if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
//         if(t1[idx1] == t2[idx2]) {
//             return dp[idx1][idx2] = 1 + backtrack(t1,t2,idx1-1,idx2-1,dp);
//         } else {
//             return dp[idx1][idx2] = max(backtrack(t1,t2,idx1-1,idx2,dp), backtrack(t1,t2,idx1,idx2-1,dp));
//         }
        
//     }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int j = 0; j < m+1; j++) dp[0][j] = 0;
        for(int i = 0; i < n+1; i++) dp[i][0] = 0;
        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < m+1; j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};