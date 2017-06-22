#
# [43] Multiply Strings
#
# https://leetcode.com/problems/multiply-strings
#
# Medium (26.75%)
# Total Accepted:    100997
# Total Submissions: 377589
# Testcase Example:  '"0"\n"0"'
#
# Given two non-negative integers num1 and num2 represented as strings, return
# the product of num1 and num2.
# 
# Note:
# 
# The length of both num1 and num2 is < 110.
# Both num1 and num2 contains only digits 0-9.
# Both num1 and num2 does not contain any leading zero.
# You must not use any built-in BigInteger library or convert the inputs to
# integer directly.
# 
# 
#
class Solution(object):
    def sigleMulti(self, c1, index1, c2, index2, res):
        index = index1 + index2
        val = int(c1) * int(c2)
        res[index] = res[index] + val
        
    def shift(self, res):
        for index in range(len(res)-2):
            val = res[index]
            res[index + 2] = res[index + 2] + int(val / 100)
            val = val % 100
            res[index + 1] = res[index + 1] + int(val / 10)
            val = val % 10
            res[index] = val
        
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        len1 = len(num1)
        len2 = len(num2)
        res = [0] * (len1 + len2 + 2)
        
        for i1 in range(len1):
            c1 = num1[i1]
            index1 = len1 - 1 - i1
            for i2 in range(len2):
                c2 = num2[i2]
                index2 = len2 -1 - i2
                self.sigleMulti(c1, index1, c2, index2, res)
                
        self.shift(res)
        head = 0
        for index in range(len(res)-1, 0, -1):
            if res[index] != 0:
                head = index
                break
        
        res = [ str(val) for val in res ][head::-1]
        
        return "".join(res)
                
            
