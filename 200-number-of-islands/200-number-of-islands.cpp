class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        //check for out of bounds
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return;
        }
        
        //check is visited(2) or if water(0)
        if(grid[r][c] == '2' || grid[r][c] == '0') {
            return;
        }
        
        // if both statements above false, then set position from 1 to 2 to make it visited
        grid[r][c] = '2';
        
        // call dfs on all directions
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int islands = 0;
        
        for(int i = 0; i  < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') { // check if position is land
                    dfs(grid, i, j); // call dfs on that position
                    islands++; // increment island counter since island found
                }
            }
        }
        
        return islands;
    }
};