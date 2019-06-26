#
# [2] Add Two Numbers
#
# https://leetcode.com/problems/add-two-numbers
#
# Medium (27.40%)
# Total Accepted:    296819
# Total Submissions: 1083299
# Testcase Example:  '[2,4,3]\n[5,6,4]'
#
# You are given two non-empty linked lists representing two non-negative
# integers. The digits are stored in reverse order and each of their nodes
# contain a single digit. Add the two numbers and return it as a linked list.
# 
# You may assume the two numbers do not contain any leading zero, except the
# number 0 itself.
# 
# 
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = None
        l = None
        flag = 0
        while l1 != None and l2 != None:
            val = flag + l1.val + l2.val
            if val >= 10:
                val = val - 10
                flag = 1
            else:
                flag = 0
            if l == None:
                l = ListNode(val)
                head = l
            else:
                l.next = ListNode(val)
                l = l.next
            l1 = l1.next
            l2 = l2.next

        left = None
        if l1 != None:
            left = l1
        elif l2 != None:
            left = l2
        while left != None:
            val = flag + left.val
            if val >= 10:
                val = val - 10
                flag = 1
            else:
                flag = 0
            if l == None:
                l = ListNode(val)
                head = l
            else:
                l.next = ListNode(val)
                l = l.next
            left = left.next
        
        if flag > 0:
            l.next = ListNode(flag)
            
        return head
                
            
                
            
        
