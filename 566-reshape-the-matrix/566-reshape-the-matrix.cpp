class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if((r*c) > (mat.size() * mat[0].size())) {
            return mat;
        }
        
        if((r*c) < (mat.size() * mat[0].size())) {
            return mat;
        }
        
        vector<int> hold;
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                hold.push_back(mat[i][j]);
            }
        }
        
        for(int i = 0; i < hold.size(); i++) {
            cout << hold[i] << " ";
        }
        
        vector<vector<int>> output;
        
        int curIdx = 0;
        
        for(int i = 0; i < r; i++) {
            vector<int> temp;
            for(int j = 0; j < c; j++) {
                temp.push_back(hold[curIdx]);
                curIdx++;
            }
            output.push_back(temp);
        }
        
        return output;
    }
};