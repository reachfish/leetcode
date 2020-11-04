/*
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree
 *
 * Hard (29.56%)
 * Total Accepted:    72429
 * Total Submissions: 245003
 * Testcase Example:  '[0,1]'
 *
 * 
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * 
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a
 * constant space solution?
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
    void recoverTree(TreeNode *p, TreeNode* &pre, TreeNode *&p1, TreeNode *&p2){
        if(!p){
            return;
        }
        
        recoverTree(p->left, pre, p1, p2);
        
        if(pre && pre->val > p->val){
            if(!p1){
                p1 = pre;
                p2 = p;
            }
            else{
                p2 = p;
            }
        }
        pre = p;
        
        recoverTree(p->right, pre, p1, p2);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode *pre = NULL, *p1 = NULL, *p2 = NULL;
        recoverTree(root, pre, p1, p2);
        
        if(p1 && p2){
            int tmp = p2->val;
            p2->val = p1->val;
            p1->val = tmp;
        }
    }
};
