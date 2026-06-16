class Solution:
    def processStr(self, s: str) -> str:
        letters = 'abcdefghijklmnopqrstuvwxyz'
        stack = []
        for i in range(len(s)):
            if s[i] in letters:
                stack.append(s[i])
            elif s[i] == '#':
                if stack:
                    stack.extend(stack)
            elif s[i] == '%':
                stack = stack[::-1]
            elif s[i] == '*':
                if len(stack) == 0:
                    continue
                stack.pop()
        res = "".join(stack)
        return res