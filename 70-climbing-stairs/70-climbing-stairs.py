class Solution:
    def climbStairs(self, n: int) -> int:
        prev2 = 1
        prev = 1
        
        for i in range(2,n+1):
            curSteps = prev2 + prev
            prev2 = prev
            prev = curSteps
        
        return prev
    
# Time Complexity: O(n)
# Space Complexity: O(1)