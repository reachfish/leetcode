/*
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view
 *
 * Medium (40.16%)
 * Total Accepted:    79079
 * Total Submissions: 196896
 * Testcase Example:  '[]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * 
 * For example:
 * Given the following binary tree,
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
 * 
 * 
 * 
 * You should return [1, 3, 4].
 * 
 * 
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all
 * test cases.
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
    void helper(TreeNode *p, int deep, vector<int>& res){
        if(!p) return;
        
        if(deep == res.size()) { res.push_back(p->val); }
        helper(p->right, deep + 1, res);
        helper(p->left, deep+1, res);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        
        helper(root, 0, res);
        return res;
    }
};
