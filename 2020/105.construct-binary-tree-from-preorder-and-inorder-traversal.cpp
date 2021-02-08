/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (51.42%)
 * Likes:    4669
 * Dislikes: 120
 * Total Accepted:    453.9K
 * Total Submissions: 880.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode* build(const vector<int>& preorder,
                    int ps,
                    int pe,
                    const vector<int>& inorder,
                    int is,
                    int ie) {
        int len = pe - ps;
        if (len <= 0 || (ie - is) != len) { return nullptr; }

        int rootv      = preorder[ps];
        TreeNode* root = new TreeNode(rootv);
        int k          = is;
        for (; k < ie; k++) {
            if (inorder[k] == rootv) { break; }
        }

        if (k == ie) { return nullptr; }

        int left_count = k - is;

        root->left  = build(preorder, ps + 1, ps + 1 + left_count, inorder, is, k);
        root->right = build(preorder, ps + 1 + left_count, pe, inorder, k + 1, ie);

        return root;
    }
};
// @lc code=end
