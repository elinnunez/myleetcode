class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        
        maxAvg = float('-inf')
        
        windowStart = 0
        
        windowSum = 0.0
        
        for windowEnd in range(len(nums)):
            
            windowSum+= nums[windowEnd]
            
            if windowEnd - windowStart + 1 >= k:
                curAvg = windowSum/k
                maxAvg = max(maxAvg,curAvg)
                windowSum-= nums[windowStart]
                windowStart+=1
        
        return maxAvg