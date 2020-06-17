/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (52.82%)
 * Likes:    4086
 * Dislikes: 583
 * Total Accepted:    984.9K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new sorted list. The new
 * list should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) {
			return l2;
		}
		if (!l2) {
			return l1;
		}

		ListNode* head = nullptr;
		ListNode* cur = nullptr;
		while (l1 && l2) {
			auto& lp = l1->val <= l2->val ? l1 : l2;
			if (cur) {
				cur->next = lp;
			} else {
				head = lp;
			}
			cur = lp;
			lp = lp->next;
		}
		cur->next = l1 ? l1 : l2;
		return head;
    }
};
// @lc code=end
