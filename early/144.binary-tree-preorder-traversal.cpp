/*
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal
 *
 * Medium (44.46%)
 * Total Accepted:    178893
 * Total Submissions: 402349
 * Testcase Example:  '[]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 
 * 
 * return [1,2,3].
 * 
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preorderTraversal(TreeNode* root, vector<int>& v){
        if(!root){
            return;
        }
        
        v.push_back(root->val);
        preorderTraversal(root->left, v);
        preorderTraversal(root->right, v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderTraversal(root, res);
        
        return res;
    }
};
