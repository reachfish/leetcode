/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (50.79%)
 * Likes:    3230
 * Dislikes: 99
 * Total Accepted:    310.9K
 * Total Submissions: 596.6K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given the head of a singly linked list where elements are sorted in
 * ascending order, convert it to a height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [-10,-3,0,5,9]
 * Output: [0,-3,9,-10,null,5]
 * Explanation: One possible answer is [0,-3,9,-10,null,5], which represents
 * the shown height balanced BST.
 *
 *
 * Example 2:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [0]
 * Output: [0]
 *
 *
 * Example 4:
 *
 *
 * Input: head = [1,3]
 * Output: [3,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in head is in the range [0, 2 * 10^4].
 * -10^5 <= Node.val <= 10^5
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    int count = 0;
    for (auto p = head; p; p = p->next) {
      count++;
    }

    return buildBST(head, count);
  }

  TreeNode* buildBST(ListNode* start, int count) {
    if (count <= 0) {
      return nullptr;
    }

    ListNode* p = start;
    int half = count / 2;
    for (int i = 0; i < half; i++) {
      p = p->next;
    }

    auto t = new TreeNode(p->val);
    t->left = buildBST(start, half);
    t->right = buildBST(p->next, count - half - 1);

    return t;
  }
};
// @lc code=end
