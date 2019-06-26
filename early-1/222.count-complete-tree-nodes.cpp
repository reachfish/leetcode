/*
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes
 *
 * Medium (27.26%)
 * Total Accepted:    60519
 * Total Submissions: 222009
 * Testcase Example:  '[]'
 *
 * Given a complete binary tree, count the number of nodes.
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        int height = 1;
        while(right){
            left = left->left;
            right = right->right;
            
            height++;
        }
        
        if(left==NULL){
            return (1<<height) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
