class Solution:
    def maxArea(self, height: List[int]) -> int:
        
        left = 0
        right = len(height) - 1
        
        maxWater = float("-inf")
        
        while left < right:
            area = (right-left) * min(height[left],height[right])
            
            maxWater = max(maxWater,area)
            
            if height[left] < height[right]:
                left+=1
            else:
                right-=1
                
        return maxWater

# Time Complexity: O(n)
# Space Complexity: O(1)