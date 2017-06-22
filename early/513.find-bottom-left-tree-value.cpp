/*
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value
 *
 * Medium (55.80%)
 * Total Accepted:    17786
 * Total Submissions: 31869
 * Testcase Example:  '[2,1,3]'
 *
 * 
 * Given a binary tree, find the leftmost value in the last row of the tree. 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Output:
 * 1
 * 
 * 
 * 
 * ⁠ Example 2: 
 * 
 * Input:
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   5   6
 * ⁠      /
 * ⁠     7
 * 
 * Output:
 * 7
 * 
 * 
 * 
 * Note:
 * You may assume the tree (i.e., the given root node) is not NULL.
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
    void find(TreeNode* p, int d, int &maxDeep, int &res){
        if(!p){
            return;
        }
        
        int deep = d + 1;
        if(deep > maxDeep){
            maxDeep = deep;
            res = p->val;
        }
        
        find(p->left, deep, maxDeep, res);
        find(p->right, deep, maxDeep, res);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int deep = 0;
        int maxDeep = 0;
        int res;
        
        find(root, deep, maxDeep, res);
        return res;
    }
};
