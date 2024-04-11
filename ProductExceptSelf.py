# 238. Product of Array except Self
class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        answer = [1] * len(nums)
        
        res = 1
        for i in range(len(nums)):
            answer[i] = res
            res *= nums[i]
        
        res = 1
        for i in range(len(nums)-1, -1, -1):
            answer[i] *= res
            res *= nums[i]
        return answer

        
