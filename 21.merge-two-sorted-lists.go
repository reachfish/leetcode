/*
 * @lc app=leetcode id=21 lang=golang
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (47.66%)
 * Total Accepted:    606K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var head, tail, curr *ListNode
	for l1 != nil && l2 != nil {
		if l1.Val <= l2.Val {
			curr = l1
			l1 = l1.Next
		} else {
			curr = l2
			l2 = l2.Next
		}
		if tail != nil {
			tail.Next = curr
		} else {
			head = curr
		}
		curr.Next = nil
		tail = curr
	}
	if l1 != nil {
		curr = l1
	} else {
		curr = l2
	}
	if curr != nil {
		if tail != nil {
			tail.Next = curr
		} else {
			head = curr
		}
	}

	return head
}
