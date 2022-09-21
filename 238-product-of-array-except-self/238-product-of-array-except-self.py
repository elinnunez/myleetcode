class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = [1] * len(nums)
        
        prefix = 1
        
        for idx in range(len(nums)):
            ans[idx] = prefix
            prefix *= nums[idx]
        
        postfix = 1
        
        for idx in range(len(nums)-1,-1,-1):
            ans[idx] *= postfix
            postfix *= nums[idx]
        
        
        return ans