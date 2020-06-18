/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (39.62%)
 * Likes:    4562
 * Dislikes: 282
 * Total Accepted:    633.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct cmp {
            bool operator()(ListNode* lh, ListNode* rh) const { return lh->val >= rh->val; }
        };

        std::priority_queue<ListNode*, std::vector<ListNode*>, cmp> que;
        for (auto node : lists) {
            if (node) {
                que.push(node);
            }
        }

        ListNode* head = nullptr;
        ListNode* cur  = nullptr;
        while (!que.empty()) {
            auto node = que.top();
            que.pop();

            if (cur) {
                cur->next = node;
            } else {
                head = node;
            }
            cur = node;
            if (!que.empty() && node->next) {
                que.push(node->next);
            }
        }

        return head;
    }
};
// @lc code=end
