class Solution {
public:
    
    void dfs(vector<vector<int>> &img, int sr, int sc, int newcolor, int src) {
        if(sr < 0 || sr >= img.size() || sc < 0 || sc >= img[0].size()) {
            return;
        }
        
        if(img[sr][sc] != src) {
            return;
        }
        
        img[sr][sc] = newcolor;
        
        dfs(img, sr+1, sc, newcolor, src);
        dfs(img, sr-1, sc, newcolor, src);
        dfs(img, sr, sc+1, newcolor, src);
        dfs(img, sr, sc-1, newcolor, src);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int source = image[sr][sc];
        
        if(newColor != source) {
            dfs(image, sr, sc, newColor, source);
        }
        
        return image;
        
    }
};