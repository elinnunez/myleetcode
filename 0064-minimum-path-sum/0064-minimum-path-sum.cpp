class Solution {
public:
    int backtrack(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return dp[i][j] = grid[i][j];
        
        if(i < 0 || j < 0) return 1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int top = grid[i][j] + backtrack(grid,i-1,j,dp);
        int left = grid[i][j] + backtrack(grid,i,j-1,dp);
        
        return dp[i][j] = min(top,left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        backtrack(grid,n-1,m-1, dp);
        
        return dp[n-1][m-1];
    }
};