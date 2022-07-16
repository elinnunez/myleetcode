class Solution:
    def isPalindrome(self, x: int) -> bool:
        num = x
        res = ""
        
        if x < 0:
            return False
        elif x == 0:
            return True

        while num > 0:
            digit = num % 10
            res = chr(digit + ord('0')) + res
            num = num // 10
            
        rev = res[::-1]
        
        return res == rev
        