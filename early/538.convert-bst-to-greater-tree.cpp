/*
 * [538] Convert BST to Greater Tree
 *
 * https://leetcode.com/problems/convert-bst-to-greater-tree
 *
 * Medium (52.80%)
 * Total Accepted:    10041
 * Total Submissions: 19017
 * Testcase Example:  '[5,2,13]'
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that
 * every key of the original BST is changed to the original key plus sum of all
 * keys greater than the original key in BST.
 * 
 * 
 * Example:
 * 
 * Input: The root of a Binary Search Tree like this:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * Output: The root of a Greater Tree like this:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
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
    TreeNode *convertBST(TreeNode *node, int &sum){
        if(!node){
            return NULL;
        }
        
        convertBST(node->right, sum);
        
        sum = sum + node->val;
        node->val = sum;
        
        convertBST(node->left, sum);
        
        return node;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        return convertBST(root, sum);
    }
};
