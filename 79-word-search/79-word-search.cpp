class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int idx, vector<vector<bool>>& visited) {
        if(idx == word.size()) {
            return true;
        }
        
        if((i < 0 || i >= board.size()) || j < 0 || j >= board[0].size()) {
            return false;
        } 
        
        if(visited[i][j] == true || board[i][j] != word[idx]) {
            return false;
        }
        
        visited[i][j] = true;
        
        bool isFound = dfs(board,i+1,j,word,idx+1,visited) ||
        dfs(board,i-1,j,word,idx+1,visited) ||
        dfs(board,i,j+1,word,idx+1,visited) ||
        dfs(board,i,j-1,word,idx+1,visited);
        
        visited[i][j] = false;
        
        return isFound;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        // create the bool vector of m size and of default value (type vector<bool>, each having size n and default values false)
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        
        bool exists = false;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    exists = dfs(board,i,j,word,0,visited);
                    if(exists == true) {
                        return true;
                    }
                }
            }
        }
        
        return exists;
    }
};
// Time Complexity: O(mn)
// Space Complexity: O(mn)