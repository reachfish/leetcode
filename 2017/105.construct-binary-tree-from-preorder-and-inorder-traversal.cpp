/*
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
 *
 * Medium (31.78%)
 * Total Accepted:    100323
 * Total Submissions: 315703
 * Testcase Example:  '[]\n[]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
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
    TreeNode* build(const vector<int>& pre, int p1, int p2, const vector<int>& inorder, int i1, int i2){
        if(p1>p2) return NULL;
        
        TreeNode *p = new TreeNode(pre[p1]);
        
        int pos;
        for(pos=i1;inorder[pos]!=pre[p1];pos++)
            ;    
        
        int len1 = pos - i1;
        int len2 = i2 - pos;
        
        p->left = build(pre, p1 + 1, p1 + len1, inorder, i1, pos - 1);
        p->right = build(pre, p1 + len1 + 1, p2, inorder, pos+1, i2);
        
        return p;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
