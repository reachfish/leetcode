/*
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii
 *
 * Easy (39.47%)
 * Total Accepted:    126949
 * Total Submissions: 321598
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
    void getLevel(TreeNode* p, vector<vector<int> >&res, int deep){
        if(!p) return;
        
        if(deep>=res.size()) res.push_back(vector<int>());
        res[deep].push_back(p->val);
        getLevel(p->left, res, deep+1);
        getLevel(p->right, res, deep+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        getLevel(root, res, 0);
        
        int i = 0;
        int j = res.size() - 1;
        while(i<j){
            swap(res[i++], res[j--]);
        }
        
        return res;
    }
};
