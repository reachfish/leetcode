/*
 * @lc app=leetcode id=19 lang=golang
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.33%)
 * Total Accepted:    406.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
 * 
 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	head, _ = iterater(head, head, n)
	return head
}

func iterater(head *ListNode, node *ListNode, n int) (*ListNode, int) {
	if node == nil {
		return head, 0
	}

	head, index := iterater(head, node.Next, n)
	index++

	if index == n + 1 {
		if node.Next != nil {
			node.Next = node.Next.Next
		} else {
			node.Next = nil
		}
	} else if node == head && n >= index {
		head = head.Next
	}

	return head, index
}
