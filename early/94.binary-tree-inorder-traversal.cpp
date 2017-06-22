/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal
 *
 * Medium (45.83%)
 * Total Accepted:    199795
 * Total Submissions: 435989
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * 
 * For example:
 * Given binary tree [1,null,2,3],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 
 * 
 * return [1,3,2].
 * 
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> values;
        
        TreeNode * p = root;
        while(p || !stk.empty()){
            while(p){
                stk.push(p);
                p = p->left;
            }
            
            
            if(!stk.empty()){
                p = stk.top();
                stk.pop();
                values.push_back(p->val);
                p = p->right;
            }
        }
        
        return values;
    }
};
