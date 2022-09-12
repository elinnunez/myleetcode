class Solution:
    def reverseString(self, s: List[str]) -> None:
        
        def reverseIt(s,i,j):
            if i>=j:
                return
            else:
                s[i],s[j] = s[j],s[i]
                i+=1
                j-=1
                reverseIt(s,i,j)
        
        reverseIt(s,0,len(s)-1)
        
        