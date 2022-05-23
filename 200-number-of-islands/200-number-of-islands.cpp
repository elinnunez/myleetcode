class Solution {
public:
    void bfs(vector<vector<char>>& graph, int i, int j) {
        
        int rdir[] = {-1, 1, 0, 0}; // row directions
        int cdir[] = {0, 0, -1, 1}; // column directions
        
        graph[i][j] = '2'; // set current position to visited
        
        queue<pair<int,int>> bag;
        bag.push({i,j}); // push current position to queue
        
        while(!bag.empty()) { // keeps looping until queue is empty
            int x = bag.front().first; // get cur row index
            int y = bag.front().second; // get cur column index
            
            bag.pop(); // pop from queue
            
            for(int d = 0; d < 4; d++) { // for looping through all possible directions combinations
                int r = rdir[d]+x; // new row position
                int c = cdir[d]+y; // new column position
                
                //if not out of bounds on new positions and unvisited land
                if(r >= 0 && r < graph.size() && c >= 0 && c < graph[i].size() && graph[r][c] == '1') {
                    bag.push({r,c}); // push to end of queue
                    graph[r][c] = '2'; // set to visited
                }
                
            }
        }
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int islands = 0;
        
        for(int i = 0; i  < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') { // check if position is unvisited land
                    islands++; // increment island counter since island found
                    bfs(grid,i,j); // bfs on position
                }
            }
        }
        
        return islands;
    }
};