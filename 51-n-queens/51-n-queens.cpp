class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        int ogRow = row;
        int ogCol = col;
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }
        
        row = ogRow;
        col = ogCol;
        
        while(col >= 0) {
            if(board[row][col] == 'Q') {
                return false;
            }
            col--;
        }
        
        col = ogCol;
        
        while(row < n && col >= 0) {
            if(board[row][col] == 'Q') {
                return false;
            }
            row++;
            col--;
        }
        
        return true;
    }
    
    void solve(vector<string>& board, int col, vector<vector<string>>& ans, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(isSafe(board,row,col, n) == true) {
                board[row][col] = 'Q';
                solve(board,col+1,ans,n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        
        vector<vector<string>> output;
        
        for(int i = 0; i < board.size(); i++) {
            board[i] = s;
        }
        
        solve(board,0,output,n);
        
        return output;    
    }
};