#
# [21] Merge Two Sorted Lists
#
# https://leetcode.com/problems/merge-two-sorted-lists
#
# Easy (38.84%)
# Total Accepted:    223426
# Total Submissions: 575231
# Testcase Example:  '[]\n[]'
#
# Merge two sorted linked lists and return it as a new list. The new list
# should be made by splicing together the nodes of the first two lists.
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1:
            return l2
        if not l2:
            return l1
            
        head = None
        l = None
        cur = None
        while l1 and l2:
            if l1.val <= l2.val:
                cur = l1
                l1 = l1.next
            else:
                cur = l2
                l2 = l2.next
                
            if not head:
                head = cur
            else:
                l.next = cur
                
            l = cur
        
        if l1:
            l.next = l1
        else:
            l.next = l2
        
        return head
                
