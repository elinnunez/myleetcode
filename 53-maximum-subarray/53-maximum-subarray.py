class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        curMax = -math.inf
        curSum = 0
        
        for num in nums:
            curSum+= num
            
            curMax = max(curMax,curSum)
            
            if curSum < 0:
                curSum = 0
        
        return curMax