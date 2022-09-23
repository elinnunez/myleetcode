class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        
        for c in s:
            if c == '(' or c == '{' or c == '[':
                stack.append(c);
            else:
                if len(stack) == 0:
                    return False
                if stack[-1] == '(' and c == ')':
                    stack.pop()
                elif stack[-1] == '{' and c == '}':
                    stack.pop()
                elif stack[-1] == '[' and c == ']':
                    stack.pop()
                else:
                    return False
        
        if len(stack) > 0:
            return False
        
        return True