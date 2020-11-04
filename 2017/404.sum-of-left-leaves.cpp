/*
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves
 *
 * Easy (46.84%)
 * Total Accepted:    50861
 * Total Submissions: 108583
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
 * 
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
    int sumOfLeft(TreeNode *node, bool isLeft){
        if(!node){
            return 0;
        }
        
        if(!node->left && !node->right){
            return isLeft ? node->val : 0;
        }
        
        int total = 0;
        if(node->left){
            total += sumOfLeft(node->left, true);
        }
        
        if(node->right){
            total += sumOfLeft(node->right, false);
        }
        
        return total;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeft(root, false);
    }
};
