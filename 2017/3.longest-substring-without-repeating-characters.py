#
# [3] Longest Substring Without Repeating Characters
#
# https://leetcode.com/problems/longest-substring-without-repeating-characters
#
# Medium (24.15%)
# Total Accepted:    297780
# Total Submissions: 1232827
# Testcase Example:  '"abcabcbb"'
#
# Given a string, find the length of the longest substring without repeating
# characters.
# 
# Examples:
# 
# Given "abcabcbb", the answer is "abc", which the length is 3.
# 
# Given "bbbbb", the answer is "b", with the length of 1.
# 
# Given "pwwkew", the answer is "wke", with the length of 3. Note that the
# answer must be a substring, "pwke" is a subsequence and not a substring.
#
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        cur_max = 0
        all_max = 0
        index = {}
        for i in range(len(s)):
            c = s[i]
            pri_c = index.get(c)
            if pri_c == None:
                pri_c = -1
            cur_max = min( i - pri_c, cur_max + 1)
            if cur_max > all_max:
                all_max = cur_max
            index[c] = i
            
        return all_max
            
        
