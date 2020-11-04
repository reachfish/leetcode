/*
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree
 *
 * Easy (38.25%)
 * Total Accepted:    174915
 * Total Submissions: 457316
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    bool isSubSymm(TreeNode *left, TreeNode* right){
        if(!left && !right){
            return true;
        }
        
        if(left && !right || !left && right){
            return false;
        }
        
        if(left->val != right->val){
            return false;
        }
        
        return isSubSymm(left->left, right->right) && isSubSymm(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }    
        
        return isSubSymm(root->left, root->right);
    }
};
