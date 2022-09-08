class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        myMap = {}
        
        count = 0
        
        maxCount = 0
        
        left = 0
        
        for r in range(len(s)):
            cur = s[r]

            if cur not in myMap:
                myMap[cur] = 0
            
            myMap[cur]+=1
            count+=1
            
            while myMap[cur] > 1: 
                myMap[s[left]] -= 1
                left+=1;
                count-=1
            
            maxCount = max(maxCount, count)
        
        return maxCount
                
            