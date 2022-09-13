class Solution: 
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        def binSearch(mat,target,i,j):
            if i > j:
                return False
            
            mid = i + (j-i)//2;
            
            if mat[mid] == target:
                return True
            else:
                if mat[mid] > target:
                    return binSearch(mat,target,i,mid-1)
                else:
                    return binSearch(mat,target,mid+1,j)
        
        m = len(matrix)
            
        for i in range(m):
            n = len(matrix[i])
            
            if matrix[i][0] == target or matrix[i][n-1] == target:
                return True
            
            if matrix[i][0] < target and target < matrix[i][n-1]:
                return binSearch(matrix[i],target,0,n-1)
        
                
        