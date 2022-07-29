class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        count = 0
        left = 0
        curSum = 0
        
        for right in range(len(arr)):
            curSum += arr[right]
            
            if right-left+1 == k:
                avg = curSum / k
                if avg >= threshold:
                    count+=1
                curSum -= arr[left]
                left+=1
        
        return count;