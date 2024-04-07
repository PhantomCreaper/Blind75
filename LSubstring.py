# Given a string s, find the length of the longest substring without repeating characters.
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        charMap = {}
        left = 0
        maxLength = 0

        for right in range(len(s)):
            if s[right] in charMap:
                left = max(left, charMap[s[right]] + 1)
            charMap[s[right]] = right
            maxLength = max(maxLength, right - left + 1)

        return maxLength
