class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for x in s:
            if x == '(':
                stack.append(')')
            elif x == '[':
                stack.append(']')
            elif x == '{':
                stack.append('}')
            else:
                if not stack or stack[-1] != x:
                    return False
                stack.pop()
        return not stack
        # general idea is the most recently added open bracket must have the first close breacket 