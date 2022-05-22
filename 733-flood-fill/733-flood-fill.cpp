class Solution {
public:
    
    void dfs(vector<vector<int>>& img, int sr, int sc, int newColor, int rows, int cols, int source) {
        if(sr < 0 || sc < 0 || sr >= rows || sc >= cols) {
            return;
        }
        
        if(img[sr][sc] == source) {
        
            img[sr][sc] = newColor;
        
            dfs(img, sr-1, sc, newColor, rows, cols, source);
            dfs(img, sr+1, sc, newColor, rows, cols, source);
            dfs(img, sr, sc-1, newColor, rows, cols, source);
            dfs(img, sr, sc+1, newColor, rows, cols, source);
        }
    } 
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int src = image[sr][sc];
        
        int rows = image.size();
        int cols = image[0].size();
        
        if(newColor == src) {
            return image;
        }
        
        dfs(image, sr, sc, newColor, rows, cols, src);
        
        return image;
        
    }
};