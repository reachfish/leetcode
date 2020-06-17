/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (35.02%)
 * Likes:    3163
 * Dislikes: 229
 * Total Accepted:    607.9K
 * Total Submissions: 1.7M
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head) {
			return nullptr;
		}

		ListNode* next = head->next;
		int my_index = -1;
		if (head == iterate(nullptr, head, n, &my_index)) {
			return next;
		} else {
			return head;
		}
    }

	ListNode* iterate(ListNode* prev, ListNode* cur, int n, int *my_index) {
		if (cur == nullptr) {
			*my_index = 0;
			return nullptr;
		}

		auto deleted = iterate(cur, cur->next, n, my_index);
		if (++(*my_index) == n) {
			deleted = cur;
			if (prev) {
				prev->next = cur->next;
			}
			delete deleted;
		}

		return deleted;
	}
};
// @lc code=end
