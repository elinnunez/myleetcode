class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int r, vector<bool>& visited) {
      visited[r] = true;
        
        for(int i = 0; i < isConnected[r].size(); i++) {
            if(isConnected[r][i] == 1 && !visited[i]) {
                dfs(isConnected,i,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        
        vector<bool> visited(isConnected.size(), false);
        
        for(int i = 0; i < isConnected.size(); i++) {
            if(!visited[i]) {
                dfs(isConnected,i,visited);
                provinces++;
            }
        }
        
        return provinces;
    }
};

/*
[1 0 0 1]
[0 1 1 0]
[0 1 1 1]
[1 0 1 1]


[1 1 0]
[1 1 0]
[0 0 1]

[1 0 0]
[0 1 0]
[0 0 1]
*/