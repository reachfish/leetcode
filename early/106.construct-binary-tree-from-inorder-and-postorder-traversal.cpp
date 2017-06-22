/*
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
 *
 * Medium (31.77%)
 * Total Accepted:    83927
 * Total Submissions: 264209
 * Testcase Example:  '[]\n[]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* build(vector<int>& in, int in1, int in2, vector<int>& post, int p1, int p2){
        if(p1>p2){
            return NULL;
        }
        
        TreeNode *node = new TreeNode(post[p2]);
        int m;
        for(m=in1;m<in2&&in[m]!=post[p2];m++)
            ;
        
        node->left = build(in, in1, m-1, post, p1, p1+(m-in1)-1);
        node->right = build(in, m+1, in2, post, p1 + (m-in1), p2 - 1);
            
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
