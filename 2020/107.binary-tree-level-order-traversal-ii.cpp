/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (54.97%)
 * Likes:    1973
 * Dislikes: 235
 * Total Accepted:    404.3K
 * Total Submissions: 734.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) { return {}; }

        std::queue<TreeNode*> que;
        que.push(root);
        que.push(nullptr);

        vector<int> level;
        vector<vector<int>> result;
        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            if (p != nullptr) {
                level.push_back(p->val);
                if (p->left) { que.push(p->left); }
                if (p->right) { que.push(p->right); }
            } else {
                result.push_back({});
                result.back().swap(level);
                if (!que.empty()) { que.push(nullptr); }
            }
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end
