/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (56.36%)
 * Likes:    4156
 * Dislikes: 101
 * Total Accepted:    766.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> que;
        if (!root) { return {}; }

        vector<vector<int>> result;
        que.push(root);
        que.push(nullptr);
        vector<int> level;
        while (!que.empty()) {
            auto p = que.front();
            que.pop();

            if (p == nullptr) {
                if (!level.empty()) { result.push_back(level); }

                if (!que.empty()) {
                    que.push(nullptr);
                } else {
                    break;
                }

                level.clear();
            } else {
                level.push_back(p->val);
                if (p->left) { que.push(p->left); }

                if (p->right) { que.push(p->right); }
            }
        }

        return result;
    }
};
// @lc code=end
