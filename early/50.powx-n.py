#
# [50] Pow(x, n)
#
# https://leetcode.com/problems/powx-n
#
# Medium (26.51%)
# Total Accepted:    150500
# Total Submissions: 567674
# Testcase Example:  '8.88023\n3'
#
# Implement pow(x, n).
# 
#
class Solution(object):
    def myPowRecurse(self, x, n):
        if n == 0:
            return 1
        val = self.myPowRecurse(x, n>>1)
        res = val * val
        if n & 1 == 1:
            res = res * x
        
        return res
        
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n >= 0:
            return self.myPowRecurse(x, n)
        else:
            return 1/self.myPowRecurse(x, -n)
