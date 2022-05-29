class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        
        left = 0
        maxCount = 0
        zeroCount = 0
        
        for i in range(len(nums)):
            if nums[i] == 0:
                zeroCount+=1;
                
            while zeroCount > k:
                if nums[left] == 0:
                    zeroCount-=1;
                left+=1
        
            maxCount = max(maxCount, i - left + 1)
            
            
        return maxCount
        