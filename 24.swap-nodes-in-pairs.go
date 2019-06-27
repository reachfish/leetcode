/*
 * @lc app=leetcode id=24 lang=golang
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (45.08%)
 * Total Accepted:    324.6K
 * Total Submissions: 719.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
func swapPairs(head *ListNode) *ListNode {
	var newhead, tail *ListNode
	curr := head
	for curr != nil && curr.Next != nil {
		currNext := curr.Next
		if tail != nil {
			tail.Next = currNext
		} else {
			newhead = currNext
		}
		curr.Next = currNext.Next
		currNext.Next = curr
		tail = curr
		curr = curr.Next
	}

	if tail == nil {
		newhead = head
	}

	return newhead
}
