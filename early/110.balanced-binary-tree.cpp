/*
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree
 *
 * Easy (37.10%)
 * Total Accepted:    172479
 * Total Submissions: 464866
 * Testcase Example:  '[]'
 *
 * Given a binary tree, determine if it is height-balanced.
 * 
 * 
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
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
    int getHeigh(TreeNode *p){
        if(!p){
            return 0;
        }
        
        int left = getHeigh(p->left);
        int right = getHeigh(p->right);
        
        if(left < 0 || right < 0 || abs(left-right) > 1){
            return -1;
        }
        
        return left > right ? left + 1 : right + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return getHeigh(root) >= 0;    
    }
};
