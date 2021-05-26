/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (56.66%)
 * Likes:    2388
 * Dislikes: 201
 * Total Accepted:    241.4K
 * Total Submissions: 424.9K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [7,2,4,3], l2 = [5,6,4]
 * Output: [7,8,0,7]
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [8,0,7]
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 *
 *
 *
 * Follow up: Could you solve it without reversing the input lists?
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
    int len1 = 0;
    int len2 = 0;

    for (auto p = l1; p; p = p->next) {
      len1++;
    }

    for (auto p = l2; p; p = p->next) {
      len2++;
    }

    ListNode* prev = nullptr;
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    int min_len = std::min(len1, len2);
    if (len1 != len2) {
      int max_len = len1 > len2 ? len1 : len2;
      ListNode*& mp = len1 > len2 ? p1 : p2;
      int diff = max_len - min_len;
      for (int i = 0; i < diff; i++, mp = mp->next) {
        prev = new ListNode(mp->val, prev);
      }
    }

    for (auto i = 0; i < min_len; i++, p1 = p1->next, p2 = p2->next) {
      prev = new ListNode(p1->val + p2->val, prev);
    }

    int flag = 0;
    ListNode* head = prev;
    prev = nullptr;
    for (;;) {
      head->val += flag;
      if (head->val >= 10) {
        head->val -= 10;
        flag = 1;
      } else {
        flag = 0;
      }

      auto next = head->next;
      head->next = prev;
      prev = head;
      if (next) {
        head = next;
      } else {
        break;
      }
    }

    if (flag) {
      head = new ListNode(flag, head);
    }

    return head;
  }
};
// @lc code=end
