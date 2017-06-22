/*
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree
 *
 * Medium (23.02%)
 * Total Accepted:    162270
 * Total Submissions: 704779
 * Testcase Example:  '[2,1,3]'
 *
 * 
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * 
 * 
 * Assume a BST is defined as follows:
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * Example 1:
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Binary tree [2,1,3], return true.
 * 
 * 
 * Example 2:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * 
 * Binary tree [1,2,3], return false.
 * 
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
    
    bool inorderTraverse(TreeNode *node, TreeNode *&pre){
        if(!node){
            return true;
        }    
        
        if(!inorderTraverse(node->left, pre)){
            return false;
        }
        
        if(pre){
            if(pre->val >= node->val){
                return false;
            }
        }
        pre = node;
        
        return inorderTraverse(node->right, pre);
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode *pre = NULL;
        return inorderTraverse(root, pre);
    }
};
