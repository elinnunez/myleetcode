class Solution {
public:
    bool binSearch(vector<int>& arr, int& target, int i, int j) {
        if(i > j) {
            return false;
        }
        
        int mid = i+(j-i)/2;
        
        if(arr[mid] == target) {
            return true;
        } else {
            if(arr[mid] > target) {
                return binSearch(arr,target,i,mid-1);
            } else {
                return binSearch(arr,target,mid+1,j);
            }
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++) { // O(m)
            if(matrix[i][0] == target || matrix[i][n-1] == target) {
                return true;
            }
            if(matrix[i][0] < target && matrix[i][n-1] > target) {
                return binSearch(matrix[i],target,0,matrix[i].size()-1); // O(logn)
            }
        }
        
        return false;
    }
};
// Time Complexity: O(mlogn)
// Space Complexity: O(1)