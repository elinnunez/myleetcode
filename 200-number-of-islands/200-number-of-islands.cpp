class Solution {
public:
//     void bfs(vector<vector<char>>& graph, int i, int j) {
        
//         int rdir[] = {-1, 1, 0, 0}; // row directions
//         int cdir[] = {0, 0, -1, 1}; // column directions
        
//         graph[i][j] = '2'; // set current position to visited
        
//         queue<pair<int,int>> bag;
//         bag.push({i,j}); // push current position to queue
        
//         while(!bag.empty()) { // keeps looping until queue is empty
//             int x = bag.front().first; // get cur row index
//             int y = bag.front().second; // get cur column index
            
//             bag.pop(); // pop from queue
            
//             for(int d = 0; d < 4; d++) { // for looping through all possible directions combinations
//                 int r = rdir[d]+x; // new row position
//                 int c = cdir[d]+y; // new column position
                
//                 //if not out of bounds on new positions and unvisited land
//                 if(r >= 0 && r < graph.size() && c >= 0 && c < graph[i].size() && graph[r][c] == '1') {
//                     bag.push({r,c}); // push to end of queue
//                     graph[r][c] = '2'; // set to visited
//                 }
                
//             }
//         }
        
        
//     }
    
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
                if(grid[i][j] == '1') { // check if position is unvisited land
                    dfs(grid,i,j); // dfs on position
                    islands++; // increment island counter since island found
                    // bfs(grid,i,j); // bfs on position
                }
            }
        }
        
        return islands;
    }
};