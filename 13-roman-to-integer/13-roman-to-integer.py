class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        
        if len(s) == 0:
            return None
        
        res = 0
        for i in range(len(s) - 1, -1, -1):
            
            if i != len(s)-1:
                print(s[i] + " vs " + s[i+1])
                if roman[s[i]] < roman[s[i+1]]:
                    res-= roman[s[i]]
                elif(roman[s[i]] >= roman[s[i+1]]):
                    res+= roman[s[i]]
            else:
                print(s[i])
                res+= roman[s[i]]
            print(f"res: {res}")
        
        return res
            
        