#
# [1] Two Sum
#
# https://leetcode.com/problems/two-sum
#
# Easy (33.37%)
# Total Accepted:    521656
# Total Submissions: 1563187
# Testcase Example:  '[3,2,4]\n6'
#
# Given an array of integers, return indices of the two numbers such that they
# add up to a specific target.
# 
# You may assume that each input would have exactly one solution, and you may
# not use the same element twice.
# 
# 
# Example:
# 
# Given nums = [2, 7, 11, 15], target = 9,
# 
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].
# 
# 
#
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ret = []
        index = {}
        for i in range(len(nums)):
            num = nums[i]
            other = target - num
            if index.has_key(other):
                ret = [ index[other], i ]
            else:
                index[num] = i
        
        return ret
