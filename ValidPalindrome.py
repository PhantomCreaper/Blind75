class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.lower()
        s = [char for char in s if char.isalnum()]
        return s == s[::-1]
