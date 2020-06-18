/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (49.71%)
 * Likes:    2171
 * Dislikes: 168
 * Total Accepted:    459.5K
 * Total Submissions: 924.4K
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* new_head = head->next;
        ListNode* prev     = nullptr;
        ListNode* n1       = head;
        ListNode* n2       = head->next;
        for (;;) {
            n1->next = n2->next;
            n2->next = n1;
            if (prev) {
                prev->next = n2;
            }
            prev = n1;
            n1   = n1->next;
            if (!n1 || !n1->next) {
                break;
            }
            n2 = n1->next;
        }

        return new_head;
    }
};
// @lc code=end
