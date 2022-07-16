class Solution:
    def isPalindrome(self, x: int) -> bool:
        res = ""
        
        if x < 0:
            return False
        elif x == 0:
            return True
        
        # Convert x: int to res: string
        while x > 0:
            digit = x % 10
            res = chr(digit + ord('0')) + res
            x = x // 10
            
        rev = res[::-1]
        
        return res == rev
        