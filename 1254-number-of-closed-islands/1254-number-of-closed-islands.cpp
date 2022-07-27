class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size()) {
            return false;
        }
        if(j < 0 || j >= grid[i].size()) {
            return false;
        }
        
        if(grid[i][j] == 1) {
            return true;
        }
        
        grid[i][j] = 1;
        
        bool l = dfs(grid,i+1,j);
        bool r = dfs(grid,i-1,j); 
        bool u = dfs(grid,i,j+1);
        bool d = dfs(grid,i,j-1);
        
        return l && r && u && d;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0) {
                    if(dfs(grid,i,j) == true) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};