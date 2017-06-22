/*
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree
 *
 * Easy (32.88%)
 * Total Accepted:    165566
 * Total Submissions: 503543
 * Testcase Example:  '[]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root) {
        if(!root) { return 0; }
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        int h = 1;
        
        if(left && right){
            h +=  left < right ? left : right;
        }
        else{
            h +=  left > right ? left : right;
        }
        
        return h;
    }
};
