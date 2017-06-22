#
# [19] Remove Nth Node From End of List
#
# https://leetcode.com/problems/remove-nth-node-from-end-of-list
#
# Medium (33.07%)
# Total Accepted:    176619
# Total Submissions: 534004
# Testcase Example:  '[1]\n1'
#
# Given a linked list, remove the nth node from the end of list and return its
# head.
# 
# 
# For example,
# 
# 
# ⁠  Given linked list: 1->2->3->4->5, and n = 2.
# 
# ⁠  After removing the second node from the end, the linked list becomes
# 1->2->3->5.
# 
# 
# 
# Note:
# Given n will always be valid.
# Try to do this in one pass.
# 
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIndexFromEnd(self, l, n):
        if not l.next:
            if n == 1:
                return 1, l
            else:
                return 1, None
        else:
            deep, node = self.getIndexFromEnd(l.next, n)
            deep = deep + 1
            if deep == n:
                node = l
            
            return deep, node
            
    def removeLast(self, head):
        end = head.next
        if not end:
            return 
        
        node = head
        while end and end.next:
            node = end
            end = end.next
        
        node.next = None
        return head
        
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if not head:
            return
        
        if n == 1:
            return self.removeLast(head)
            
        index, node = self.getIndexFromEnd(head, n)
        if not node:
            return head 
        
        if not node.next:
            return 
        
        node.val = node.next.val
        node.next = node.next.next
        
        return head
        
