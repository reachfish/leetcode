/*
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum
 *
 * Easy (33.68%)
 * Total Accepted:    161696
 * Total Submissions: 480170
 * Testcase Example:  '[]\n1'
 *
 * 
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        
        sum -= root->val;
        if(!root->left && !root->right){
            return sum == 0;
        }
        
        bool res = false;
        if (root->left){
            res = res || hasPathSum(root->left, sum);
        }
        if(root->right){
            res = res || hasPathSum(root->right, sum);
        }
        
        return res;
    }
};
