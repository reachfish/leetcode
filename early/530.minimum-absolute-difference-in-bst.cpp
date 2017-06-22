/*
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst
 *
 * Easy (47.07%)
 * Total Accepted:    15778
 * Total Submissions: 33523
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 * 
 * 
 * Example:
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * Output:
 * 1
 * 
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 * 
 * 
 * 
 * 
 * Note:
 * There are at least two nodes in this BST.
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

    void inorderSearch(TreeNode* node, TreeNode* &pre, int &min){
        if(!node){
            return;
        }
        
        inorderSearch(node->left, pre, min);
        
        if(pre){
            int val = abs(pre->val - node->val);
            min = min < val ? min : val;
        }
        
        pre = node;
        
        inorderSearch(node->right, pre, min);
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        int min = INT_MAX;
        TreeNode* pre = NULL;
        
        inorderSearch(root, pre, min);
        
        return min;
    }
};
