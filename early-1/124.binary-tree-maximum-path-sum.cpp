/*
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum
 *
 * Hard (25.73%)
 * Total Accepted:    95624
 * Total Submissions: 371665
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a binary tree, find the maximum path sum.
 * 
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * 
 * For example:
 * Given the below binary tree,
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 
 * 
 * Return 6.
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
    int maxN(int a, int b){
        return a > b ? a : b;    
    }
    
    int maxPath(TreeNode *p, int &max){
        if(!p){
            return 0;
        }
        
        int left = maxPath(p->left, max);
        int right = maxPath(p->right, max);
        
        int sigle = maxN(p->val, p->val+maxN(left, right));
        max = maxN(max, maxN(sigle, left + right + p->val));
        
        return sigle;
    }
    
    int maxPathSum(TreeNode* root) {
        int max = INT_MIN;
        maxPath(root, max);
        
        return max;
    }
};
