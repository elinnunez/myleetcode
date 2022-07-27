class Solution {
public:
    bool dfs(vector<vector<int>>&grid, int i, int j, vector<vector<bool>>& visited, int& count) {
        if(i < 0 || i >= grid.size()) {
            return false;
        }
        if(j < 0 || j >= grid[i].size()) {
            return false;
        }
        
        if(grid[i][j] == 0 || visited[i][j] == true) {
            return false;
        }
        
        count++;
        visited[i][j] = true;
        
        dfs(grid,i+1,j,visited,count);
        dfs(grid,i-1,j,visited,count);
        dfs(grid,i,j+1,visited,count);
        dfs(grid,i,j-1,visited,count);
        return true;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited;
        for(int i = 0; i < grid.size(); i++) {
            vector<bool> temp(grid[i].size(), false);
            visited.push_back(temp);
        }
        
        int count = 0;
        int maxCount = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    if(dfs(grid,i,j,visited,count) == true) {
                        maxCount = max(count, maxCount);
                        count = 0;
                    }
                }
            }
        }
        
        return maxCount;
    }
};