class Solution {
public:
    bool binSearch(vector<int>& arr, int left, int right, int element) {
        while (left <= right) 
        { 
            int middle = left + (right - left) / 2; 
            // Check if element is present at middle position or not 
            if (arr[middle] == element) 
                return true; 
            // If element is greater, ignore left half 
            if (arr[middle] < element) 
                left = middle + 1; 
            // If element is smaller, ignore right half 
            else
                right = middle - 1; 
        } 
        // if element is not present then return false
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] == target || matrix[i][matrix[i].size()-1] == target) {
                return true;
            }
            if(matrix[i][0] < target && target < matrix[i][matrix[i].size()-1]) {
                return binSearch(matrix[i], 0, matrix[i].size()-1, target);
            }
        }
        
        return false;
    }
};