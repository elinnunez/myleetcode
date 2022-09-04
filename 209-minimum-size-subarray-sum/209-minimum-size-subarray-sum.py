class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        minSize = len(nums)+1
        curSum = 0
        windowStart = 0
        
        for windowEnd in range(len(nums)):
            
            if nums[windowEnd] == target:
                return 1
            
            curSum+= nums[windowEnd]
                
            while curSum >= target:
                curSize = windowEnd - windowStart + 1
                minSize = min(minSize, curSize)
                curSum-= nums[windowStart]
                windowStart+=1
                
        
        if minSize == len(nums)+1:
            return 0
        
        return minSize
    
