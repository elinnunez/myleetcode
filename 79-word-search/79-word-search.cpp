class Solution {
public:
    bool dfs(vector<vector<char>>& board, int r, int c, int idx, string& word, vector<vector<bool>>& visited) {
        if(idx == word.size()) {
            return true;
        }
        
        if(r < 0 || r >= board.size() || c < 0 || c >= board[r].size()) {
            return false;
        }
        
        if(board[r][c] != word[idx] || visited[r][c] == true) {
            return false;
        }
        
        visited[r][c] = true;
        
        bool response = dfs(board,r+1,c,idx+1,word,visited) || 
                        dfs(board,r-1,c,idx+1,word,visited) || 
                        dfs(board,r,c+1,idx+1,word,visited) || 
                        dfs(board,r,c-1,idx+1,word,visited);  
        
        visited[r][c] = false;
        
        return response;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board,i,j,0,word,visited)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
// Time Complexity: O(mn)
// Space Complexity: O(mn)