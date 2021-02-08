/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (49.88%)
 * Likes:    3045
 * Dislikes: 122
 * Total Accepted:    470.4K
 * Total Submissions: 941.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) { return {}; }

        vector<vector<int>> result;
        vector<TreeNode*> lvl[2];
        lvl[0].push_back(root);
        int index = 0;

        while (!lvl[index].empty()) {
            result.push_back({});
            auto& vec   = result.back();
            auto& cur   = lvl[index];
            auto& other = lvl[1 - index];
            if (index == 0) {
                for (auto it = cur.begin(); it != cur.end(); it++) {
                    auto p = *it;
                    vec.push_back(p->val);
                    if (p->left) { other.push_back(p->left); }
                    if (p->right) { other.push_back(p->right); }
                }
            } else {
                for (auto it = cur.rbegin(); it != cur.rend(); it++) {
                    auto p = *it;
                    vec.push_back(p->val);
                    if (p->right) { other.push_back(p->right); }
                    if (p->left) { other.push_back(p->left); }
                }
                std::reverse(other.begin(), other.end());
            }

            cur.clear();
            index = 1 - index;
        }

        return result;
    }
};
// @lc code=end
