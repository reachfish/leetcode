/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (55.84%)
 * Likes:    3657
 * Dislikes: 198
 * Total Accepted:    425K
 * Total Submissions: 752.6K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it, return the values of the nodes you can see ordered from top to
 * bottom.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,5,null,4]
 * Output: [1,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,null,3]
 * Output: [1,3]
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    helper(root, 0, &result);
    return result;
  }

  void helper(TreeNode* p, int depth, vector<int>* result) {
    if (!p) {
      return;
    }

    if (depth == result->size()) {
      result->push_back(p->val);
    }

    helper(p->right, depth + 1, result);
    helper(p->left, depth + 1, result);
  }
};
// @lc code=end
