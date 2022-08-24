class Solution {
public:
    bool isMatch(string s, string p) {
        if(p == "*") {
            return true;
        }
        
        int m = s.size();
        int n = p.size();
        
        bool dp[m+1][n+1];
        memset(dp,false,sizeof(dp));
        
        dp[0][0] = true;
        
        for(int i = 1; i < n+1; i++) {
            if(p[i-1] != '*') {
                break;
            }
            dp[0][i] = true;
        }
        
        for(int i = 1; i < m+1; i++) {
            for(int j = 1; j < n+1; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[m][n];
        
    }
};
// Time Complexity: O(mn)
// Space Complexity: O(mn)