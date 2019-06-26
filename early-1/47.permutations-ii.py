#
# [47] Permutations II
#
# https://leetcode.com/problems/permutations-ii
#
# Medium (32.22%)
# Total Accepted:    117919
# Total Submissions: 366023
# Testcase Example:  '[1,1,2]'
#
# 
# Given a collection of numbers that might contain duplicates, return all
# possible unique permutations.
# 
# 
# 
# For example,
# [1,1,2] have the following unique permutations:
# 
# [
# ⁠ [1,1,2],
# ⁠ [1,2,1],
# ⁠ [2,1,1]
# ]
# 
# 
#
class Solution(object):
    def permuteUniqueRecurse(self, nums, index, all):
        size = len(nums)
        if index == size:
            all.append(nums[:])
            return 
        if index > size:
            return 
        
        self.permuteUniqueRecurse(nums, index + 1, all)
        
        m = {}
        for i in range(index+1, len(nums)):
            a, b = nums[index], nums[i]
            if a != b and not m.has_key(b):
                m[b] = 1
                nums[index], nums[i] = b, a
                self.permuteUniqueRecurse(nums, index + 1, all)
                nums[index], nums[i] = a, b
        
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        all = []
        self.permuteUniqueRecurse(nums, 0, all)
        
        return all
