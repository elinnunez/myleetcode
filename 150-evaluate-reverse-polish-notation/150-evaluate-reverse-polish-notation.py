class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        val = 0
        for token in tokens:
            if token not in "+-*/":
                stack.append(int(token))
                continue
            v2 = stack.pop()
            v1 = stack.pop()
            if token =="+":
                val = v1+v2
            elif token == "-":
                val = v1-v2
            elif token == "*":
                val = v1*v2
            else:
                val = int(v1/v2)
            stack.append(val)
        return stack.pop()