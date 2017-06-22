#
# [20] Valid Parentheses
#
# https://leetcode.com/problems/valid-parentheses
#
# Easy (33.14%)
# Total Accepted:    202472
# Total Submissions: 611038
# Testcase Example:  '"["'
#
# Given a string containing just the characters '(', ')', '{', '}', '[' and
# ']', determine if the input string is valid.
# 
# The brackets must close in the correct order, "()" and "()[]{}" are all valid
# but "(]" and "([)]" are not.
# 
#
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        count = 0
        match = { '{':'}', '[':']', '(':')' }
        for c in s:
            if match.has_key(c):
                stack.append(c)
            else:
                if not stack:
                    return False
                top = stack.pop()
                if c != match[top]:
                    return False
            count = count + 1
        
        return count == len(s) and not stack
            
        
