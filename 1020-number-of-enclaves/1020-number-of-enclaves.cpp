class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size()) {
            return;
        }
        if(j < 0 || j >= grid[i].size()) {
            return;
        }

        if(grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;

        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
        return;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    if(i == 0 || i == grid.size()-1 || j == 0 || j == grid[i].size()-1) {
                        dfs(grid,i,j);
                    }
                }
            }
        }

        int landCount = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    landCount++;
                }
            }
        }

        return landCount;
    }
};