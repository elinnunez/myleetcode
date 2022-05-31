class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        
        ht = {}
        
        for num in nums:
            if num not in ht:
                ht[num] = 1
            else:
                ht[num]+=1
                
            if ht[num] > 1:
                return True
        
        return False
        