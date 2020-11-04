/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (37.49%)
 * Likes:    2095
 * Dislikes: 113
 * Total Accepted:    273.4K
 * Total Submissions: 728.5K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Return the linked list sorted as well.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* new_head = nullptr;
        ListNode* prev     = nullptr;

        for (auto p = head; p;) {
            auto next = p->next;
            if (!next || p->val != next->val) {
                prev = p;
                if (!new_head) {
                    new_head = p;
                }
                p = p->next;
            } else {
                auto val = p->val;
                while (p && p->val == val) {
                    auto next = p->next;
                    delete p;
                    p = next;
                    if (prev) {
                        prev->next = next;
                    }
                }
            }
        }

        return new_head;
    }
};
// @lc code=end
