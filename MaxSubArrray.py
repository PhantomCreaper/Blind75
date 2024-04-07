class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxs = nums[0]
        cur = 0
        for i in nums:
            if cur < 0:
                cur = 0
            cur += i
            maxs = max(maxs, cur)

        return maxs
