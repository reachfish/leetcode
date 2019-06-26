/*
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii
 *
 * Medium (42.92%)
 * Total Accepted:    42292
 * Total Submissions: 98532
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * 
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called the "root." Besides the root, each
 * house has one and only one parent house. After a tour, the smart thief
 * realized that "all houses in this place forms a binary tree". It will
 * automatically contact the police if two directly-linked houses were broken
 * into on the same night.
 * 
 * 
 * 
 * Determine the maximum amount of money the thief can rob tonight without
 * alerting the police.
 * 
 * 
 * Example 1:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \ 
 * ⁠    3   1
 * 
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * 
 * 
 * Example 2:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \ 
 * ⁠1   3   1
 * 
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
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
    int max(int a, int b) {
        return a > b ? a : b;
    }
    
    int rob(TreeNode* p, int &grandMax){
        if(!p) { grandMax = 0; return 0; }
        int leftGrand, rightGrand;
        
        int left = rob(p->left, leftGrand);
        int right = rob(p->right, rightGrand);
        
        grandMax = left + right;
        
        return max(leftGrand+rightGrand+p->val,  left + right);
    }
    
    int rob(TreeNode* root) {
        int grandMax;
        
        return rob(root, grandMax);
    }
};
