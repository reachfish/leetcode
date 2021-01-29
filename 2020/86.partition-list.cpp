/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (42.37%)
 * Likes:    1795
 * Dislikes: 360
 * Total Accepted:    245.4K
 * Total Submissions: 568.9K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given the head of a linked list and a value x, partition it such that all
 * nodes less than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,4,3,2,5,2], x = 3
 * Output: [1,2,2,4,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [2,1], x = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 200].
 * -100 <= Node.val <= 100
 * -200 <= x <= 200
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_h  = nullptr;
        ListNode* less_c  = nullptr;
        ListNode* large_h = nullptr;
        ListNode* large_c = nullptr;

        for (auto p = head; p != nullptr; p = p->next) {
            ListNode*& h = p->val < x ? less_h : large_h;
            ListNode*& c = p->val < x ? less_c : large_c;

            if (h == nullptr) { h = p; }
            if (c != nullptr) { c->next = p; }

            c = p;
        }

        if (large_c) { large_c->next = nullptr; }

        if (less_c) {
            less_c->next = large_h;
            return less_h;
        } else {
            return large_h;
        }
    }
};
// @lc code=end
