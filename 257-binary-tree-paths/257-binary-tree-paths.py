# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
        
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        paths = []
        
        def helper(root, paths, currentPath):
            if not root:
                return
            
            currentPath += str(root.val) + "->"
            
            if not root.left and not root.right:
                # Strip the right 
                path = currentPath.rstrip("->")
                # Add to paths
                paths.append(path)
                
            helper(root.left, paths, currentPath)
            helper(root.right, paths, currentPath)
            
        helper(root, paths, "")
        
        return paths
        