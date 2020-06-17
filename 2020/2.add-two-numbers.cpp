/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (33.49%)
 * Likes:    8130
 * Dislikes: 2070
 * Total Accepted:    1.4M
 * Total Submissions: 4.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = nullptr;
		ListNode* prev = nullptr;
		int flag = 0;
		while (l1 || l2 || flag > 0) {
			int value = flag;
			if (l1) {
				value += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				value += l2->val;
				l2 = l2->next;
			}

			if (value >= 10) {
				value -= 10;
				flag = 1;
			} else {
				flag = 0;
			}

			ListNode* cur = new ListNode(value);
			if (prev) {
				prev->next = cur;
			} else {
				head = prev;
			}
			prev = cur;
		}

		return head;
    }
};
// @lc code=end
