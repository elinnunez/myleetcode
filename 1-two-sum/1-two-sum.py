class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        hashmap = {}
        
        arr = []
        
        for idx, item in enumerate(nums):
            if (target-item) not in hashmap:
                hashmap[item] = idx
            else:
                arr.append(hashmap[target-item])
                arr.append(idx)
            
        return arr