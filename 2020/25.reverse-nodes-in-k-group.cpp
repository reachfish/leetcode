/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (41.21%)
 * Likes:    2086
 * Dislikes: 357
 * Total Accepted:    262.1K
 * Total Submissions: 635.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) {
            return head;
        }

        ListNode* new_head        = nullptr;
        ListNode* last_group_tail = nullptr;
        auto h                    = head;
        for (;;) {
            auto t = GetGroupTail(h, k);
            if (!t) {
                break;
            }
            Reverse(last_group_tail, h, t);
            std::swap(h, t);
            last_group_tail = t;
            if (!new_head) {
                new_head = h;
            }
            h = t->next;
        }

        return new_head ? new_head : head;
    }

    ListNode* GetGroupTail(ListNode* h, int k) {
        ListNode* cur = h;
        for (int i = 1; i < k && cur; cur = cur->next, i++) {
        }
        return cur;
    }

    void Reverse(ListNode* last_group_tail, ListNode* h, ListNode* t) {
        ListNode* next_group_begin = t->next;

        ListNode* p    = h;
        ListNode* prev = nullptr;
        while (p != next_group_begin) {
            auto next = p->next;
            p->next   = prev;
            prev      = p;
            p         = next;
        }

        if (last_group_tail) {
            last_group_tail->next = t;
        }
        h->next = next_group_begin;
    }
};
// @lc code=end
