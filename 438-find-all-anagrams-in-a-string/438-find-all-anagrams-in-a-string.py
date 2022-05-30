class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        
        out = []
        
        ht = {}
        
        left = 0
        matches = 0
        
        for i in range(len(p)):
            if p[i] not in ht:
                ht[p[i]] = 1
            else:
                ht[p[i]]+=1
        
        for r in range(len(s)):
            curChar = s[r]
            
            if curChar in ht:
                ht[curChar]-=1
                if ht[curChar] == 0:
                    matches+=1
            
            if matches == len(ht):
                out.append(left)
            
            if r >= len(p) - 1:
                leftChar = s[left]
                if leftChar in ht:
                    if ht[leftChar] == 0:
                        matches-=1
                    ht[leftChar]+=1
                left+=1
        
        return out
            
            
        