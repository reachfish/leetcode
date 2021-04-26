/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (56.93%)
 * Likes:    3034
 * Dislikes: 341
 * Total Accepted:    369.7K
 * Total Submissions: 645K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered
 * list.
 *
 * The first node is considered odd, and the second node is even, and so on.
 *
 * Note that the relative order inside both the even and odd groups should
 * remain as it was in the input.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [1,3,5,2,4]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [2,1,3,5,6,4,7]
 * Output: [2,3,6,7,1,5,4]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the linked list is in the range [0, 10^4].
 * -10^6 <= Node.val <= 10^6
 *
 *
 *
 * Follow up: Could you solve it in O(1) space complexity and O(nodes) time
 * complexity?
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
  ListNode* oddEvenList(ListNode* head) {
    ListNode* odd = nullptr;
    ListNode* even = nullptr;
    ListNode* even_head = nullptr;
    bool is_odd = true;
    for (ListNode* p = head; p; is_odd = !is_odd) {
      ListNode* next = p->next;
      if (is_odd) {
        if (odd) {
          odd->next = p;
        }
        odd = p;
      } else {
        if (even) {
          even->next = p;
        } else {
          even_head = p;
        }
        even = p;
      }

      p->next = nullptr;
      p = next;
    }

    if (odd) {
      odd->next = even_head;
    }

    return head;
  }
};
// @lc code=end
