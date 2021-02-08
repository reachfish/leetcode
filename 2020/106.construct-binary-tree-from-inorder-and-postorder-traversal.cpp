/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (49.31%)
 * Likes:    2415
 * Dislikes: 44
 * Total Accepted:    279.1K
 * Total Submissions: 564.7K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* build(const vector<int>& inorder,
                    int is,
                    int ie,
                    const vector<int>& postorder,
                    int ps,
                    int pe) {
        int len = ie - is;
        if (len < 0 || (pe - ps) != len) { return nullptr; }

        int k     = is;
        int rootv = postorder[pe];
        for (; k <= ie; k++) {
            if (inorder[k] == rootv) { break; }
        }

        if (k > ie) { return nullptr; }

        int left_count = k - is;

        TreeNode* root = new TreeNode(rootv);
        root->left     = build(inorder, is, k - 1, postorder, ps, ps + left_count - 1);
        root->right    = build(inorder, k + 1, ie, postorder, ps + left_count, pe - 1);

        return root;
    }
};
// @lc code=end
