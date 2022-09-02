class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<vector<int>> zeroElt;
        
        int count = 0;
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    zeroElt.insert({i,j});
                    count++;
                }
            }
        }
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0 && zeroElt.count({i,j})) {
                    for(int k = 0; k < matrix.size(); k++) {
                        matrix[k][j] = 0;
                    }
                    for(int l = 0; l < matrix[i].size(); l++) {
                        matrix[i][l] = 0;
                    }
                    count--;
                }
                if(count == 0) {
                    return;
                }
            }
        }
        
        return;
    }
};