/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Medium (37.65%)
 * Likes:    2347
 * Dislikes: 564
 * Total Accepted:    116.5K
 * Total Submissions: 307.9K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given the root of a binary tree, return the length of the longest path,
 * where each node in the path has the same value. This path may or may not
 * pass through the root.
 *
 * The length of the path between two nodes is represented by the number of
 * edges between them.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,4,5,1,1,5]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,4,5,4,4,5]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 * The depth of the tree will not exceed 1000.
 *
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
  int longestUnivaluePath(TreeNode* root) {
    int longest = 0;
    dfs(root, longest);
    return longest;
  }

  int dfs(TreeNode* p, int& longest) {
    if (!p) {
      return 0;
    }

    int lh = dfs(p->left, longest);
    int rh = dfs(p->right, longest);

    if (p->left && p->left->val == p->val) {
      lh++;
    } else {
      lh = 0;
    }

    if (p->right && p->right->val == p->val) {
      rh++;
    } else {
      rh = 0;
    }

    longest = std::max(longest, lh + rh);

    return std::max(lh, rh);
  }
};
// @lc code=end
