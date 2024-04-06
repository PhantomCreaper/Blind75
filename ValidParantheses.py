# 125. Valid Parantheses
#Main not included
class Solution:
    def isValid(self, s):
        stack = []
        bracket_mapping = {')': '(', '}': '{', ']': '['}

        for char in s:
            if char in bracket_mapping.values():
                stack.append(char)
            elif char in bracket_mapping.keys():
                if not stack or stack.pop() != bracket_mapping[char]:
                    return False
        return len(stack)==0
