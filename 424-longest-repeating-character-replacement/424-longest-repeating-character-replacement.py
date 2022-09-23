class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        myMap = {}
        
        maxFreq = 0
        
        maxLen = 0
        
        left = 0
        
        for r in range(len(s)):
            cur = s[r]
            
            if cur not in myMap:
                myMap[cur] = 0
            
            myMap[cur] += 1
            
            maxFreq = max(maxFreq,myMap[cur])
            
            if ((r-left+1)-maxFreq) > k: # if window is has greater than k replacements
                curL = s[left]
                myMap[curL] -= 1
                left += 1
            
            maxLen = max(maxLen, r-left+1)
        
        return maxLen
    
# Time Complexity: O(n)
# Space Complexity: O(n)
                