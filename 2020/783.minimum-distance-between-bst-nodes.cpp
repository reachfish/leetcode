/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 *
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (54.33%)
 * Likes:    1110
 * Dislikes: 263
 * Total Accepted:    92.6K
 * Total Submissions: 169.8K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * Given the root of a Binary Search Tree (BST), return the minimum difference
 * between the values of any two different nodes in the tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [4,2,6,1,3]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,0,48,null,null,12,49]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 100].
 * 0 <= Node.val <= 10^5
 *
 *
 *
 * Note: This question is the same as 530:
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 *
 */

// @lc code=start
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
  int minDiffInBST(TreeNode* root) {
    int min_diff = INT_MAX;
    TreeNode* prev = nullptr;
    minDiff(root, prev, &min_diff);

    return min_diff;
  }

  void minDiff(TreeNode* cur, TreeNode*& prev, int* min_diff) {
    if (!cur) {
      return;
    }
    minDiff(cur->left, prev, min_diff);
    if (prev) {
      int diff = cur->val - prev->val;
      if (diff < *min_diff) {
        *min_diff = diff;
      }
    }
    prev = cur;
    minDiff(cur->right, prev, min_diff);
  }
};
// @lc code=end
