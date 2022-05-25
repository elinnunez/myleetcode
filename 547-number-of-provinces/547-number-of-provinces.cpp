class Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected, vector<bool>& vi, int r) {
        
        //set current row to visited since we're going to loop through it's array;
        vi[r] = true;
        //loop through row array
        for(int i = 0; i < isConnected[r].size(); i++) {
            //if valid location and the index hasn't been visited call dfs recursively
            if(isConnected[r][i] && !vi[i]) {
                dfs(isConnected, vi, i);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int count = 0;
        
        vector<bool> visited(isConnected.size(), false); // set every index to false since unvisited atm
        
        for(int i = 0; i < isConnected.size(); i++) {
                if(!visited[i]) {
                    dfs(isConnected, visited, i);
                    count++;
            }
        }
        
        return count;
        
    }
};