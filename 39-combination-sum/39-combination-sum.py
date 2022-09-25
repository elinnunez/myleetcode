class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        output = []
        
        def helper(idx,curSum, li):
            if curSum == 0:
                output.append(li.copy())
                return
            
            if curSum < 0 or idx >= len(candidates):
                return
            
            li.append(candidates[idx])
            helper(idx,curSum-candidates[idx],li)
            li.pop()
            helper(idx+1,curSum,li)
        
        helper(0,target,[])
        
        return output