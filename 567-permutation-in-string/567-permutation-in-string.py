class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        left = 0
        matches = 0
        
        ht = {}
        
        for i in range(len(s1)):
            if s1[i] not in ht:
                ht[s1[i]] = 1
            else:
                ht[s1[i]]+=1
        
        for r in range(len(s2)):
            curChar = s2[r]
            
            if curChar in ht:
                ht[curChar]-=1
                if ht[curChar] == 0:
                    matches+=1
            
            if(matches == len(ht)):
                return True
            
            if(r >= len(s1) - 1):
                leftChar = s2[left]
                if leftChar in ht:
                    if ht[leftChar] == 0:
                        matches-=1
                    ht[leftChar]+=1
                left+=1
                
            
        return False
        