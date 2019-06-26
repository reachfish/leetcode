/*
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree
 *
 * Easy (46.14%)
 * Total Accepted:    201938
 * Total Submissions: 437666
 * Testcase Example:  '[]\n[]'
 *
 * 
 * Given two binary trees, write a function to check if they are equal or
 * not.
 * 
 * 
 * Two binary trees are considered equal if they are structurally identical and
 * the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p){
            return p == q;
        }
        else{
            if(!q||p->val!=q->val){
                return false;
            }   
        }
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
