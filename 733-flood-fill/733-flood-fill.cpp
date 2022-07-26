class Solution {
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int og) {
        if(sr < 0 || sr >= image.size()) {
            return;
        }
        if(sc < 0 || sc >= image[0].size()) {
            return;
        }
        
        if(image[sr][sc] != og || image[sr][sc] == color) {
            return;
        }
        
        image[sr][sc] = color;
        
        dfs(image, sr+1, sc, color, og);
        dfs(image, sr-1, sc, color, og);
        dfs(image, sr, sc+1, color, og);
        dfs(image, sr, sc-1, color, og);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int og = image[sr][sc];
        dfs(image, sr, sc, color, og);
        
        return image;
        
    }
};