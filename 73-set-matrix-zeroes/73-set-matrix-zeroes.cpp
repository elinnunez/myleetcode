class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>> zeroElt;
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    zeroElt.insert(make_pair(i,j));
                }
            }
        }
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                for(const auto& pair : zeroElt) {
                    if(pair.first == i || pair.second == j) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        
        return;
    }
};
// Time Complexity: O(mno) where o = size of set
// Space Complexity: O(1)