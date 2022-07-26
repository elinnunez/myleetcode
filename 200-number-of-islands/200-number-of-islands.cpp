class Solution {
public:
    void dfs (vector<vector<char>>& grid, int row, int col) {
        if(row < 0 || row >= grid.size()) {
            return;
        }
        
        if(col < 0 || col >= grid[0].size()) {
            return;
        }
        
        if(grid[row][col] == '2' || grid[row][col] == '0') {
            return;
        }
        
        grid[row][col] = '2';
             
        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
        dfs(grid, row, col+1);
        dfs(grid, row, col-1);             
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};