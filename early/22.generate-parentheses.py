#
# [22] Generate Parentheses
#
# https://leetcode.com/problems/generate-parentheses
#
# Medium (44.00%)
# Total Accepted:    145535
# Total Submissions: 330794
# Testcase Example:  '3'
#
# 
# Given n pairs of parentheses, write a function to generate all combinations
# of well-formed parentheses.
# 
# 
# 
# For example, given n = 3, a solution set is:
# 
# 
# [
# ⁠ "((()))",
# ⁠ "(()())",
# ⁠ "(())()",
# ⁠ "()(())",
# ⁠ "()()()"
# ]
# 
#
class Solution(object):
    def generateSeq(self, m, n, left, right, seq, res):
        if left < right or left > right + (2*n - m):
            return 
        if m == 2*n:
            if left == right:
                res.append("".join(seq))
            return 
        seq[m] = "("
        self.generateSeq(m+1, n, left + 1, right, seq, res)
        seq[m] = ")"
        self.generateSeq(m+1, n, left, right + 1, seq, res)
        
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        seq = [ 0 for i in range(2*n) ]
        res = []
        self.generateSeq(0, n, 0, 0, seq, res)
        
        return res
