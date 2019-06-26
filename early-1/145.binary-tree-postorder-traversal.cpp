/*
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal
 *
 * Hard (39.68%)
 * Total Accepted:    140974
 * Total Submissions: 355254
 * Testcase Example:  '[]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 
 * 
 * return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode*> stk;
        if(root){
            stk.push(root);
        }
        
        TreeNode *pre = NULL;
        while(!stk.empty()){
            TreeNode *p = stk.top();
            if(!p->left && !p->right || pre==p->right && p->right || pre==p->left && !p->right){
                res.push_back(p->val);
                pre = p;
                stk.pop();
            }
            else{
                if(pre!=p->left && p->left){
                    stk.push(p->left);
                }
                else{
                    stk.push(p->right);
                }
            }
        }
        
        return res;
    }
};
