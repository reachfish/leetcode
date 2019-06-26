#
# [46] Permutations
#
# https://leetcode.com/problems/permutations
#
# Medium (42.74%)
# Total Accepted:    164487
# Total Submissions: 384821
# Testcase Example:  '[1,2,3]'
#
# 
# Given a collection of distinct numbers, return all possible permutations.
# 
# 
# 
# For example,
# [1,2,3] have the following permutations:
# 
# [
# ⁠ [1,2,3],
# ⁠ [1,3,2],
# ⁠ [2,1,3],
# ⁠ [2,3,1],
# ⁠ [3,1,2],
# ⁠ [3,2,1]
# ]
# 
# 
#
class Solution(object):
    def permuteRecurse(self, nums, index, all):
        if index == len(nums):
            all.append(nums[:])
            return 
        for i in range(index, len(nums)):
            a, b = nums[index], nums[i]
            nums[index], nums[i] = nums[i], nums[index]
            self.permuteRecurse(nums, index + 1, all)
            nums[index], nums[i] = a, b
        
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        all = []
        self.permuteRecurse(nums, 0, all)
        
        return all
