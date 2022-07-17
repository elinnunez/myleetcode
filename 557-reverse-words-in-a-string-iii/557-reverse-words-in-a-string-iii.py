class Solution:
    def reverseWords(self, s: str) -> str:
        splitS = s.split();
        
        for idx in range(len(splitS)):
            splitS[idx] = splitS[idx][::-1]
        
        return " ".join(splitS)
            