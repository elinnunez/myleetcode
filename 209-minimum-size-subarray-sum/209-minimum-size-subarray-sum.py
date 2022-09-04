class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        minSize = len(nums)+1 # initialize a max value
        winSum = 0 # set current sum to 0
        windowStart = 0 # set begining of window to index 0
        
        for windowEnd in range(len(nums)):
            
            if nums[windowEnd] >= target: # if the value is >= to target return 1 since that's the smallest an array can be
                return 1
            
            winSum+= nums[windowEnd]
                
            while winSum >= target: # keep looping while the sum is >= to target
                winSize = windowEnd - windowStart + 1 # get current size of window
                minSize = min(minSize, winSize) # get min window size from prev minSize and current size
                winSum-= nums[windowStart] # subtract the winSum from the left as its being removed from windows
                windowStart+=1 # increment windowStart from the left
                
        
        if minSize == len(nums)+1: # if nothing was found and minSize is still at default max value return 0
            return 0
        
        return minSize
    
# Time Complexity: O(n)
# Space Complexity: O(1)