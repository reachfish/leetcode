/*
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list
 *
 * Medium (34.62%)
 * Total Accepted:    125059
 * Total Submissions: 361272
 * Testcase Example:  '[]'
 *
 * 
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * 
 * 
 * For example,
 * Given
 * 
 * ⁠        1
 * ⁠       / \
 * ⁠      2   5
 * ⁠     / \   \
 * ⁠    3   4   6
 * 
 * 
 * 
 * The flattened tree should look like:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠     \
 * ⁠      3
 * ⁠       \
 * ⁠        4
 * ⁠         \
 * ⁠          5
 * ⁠           \
 * ⁠            6
 * 
 * 
 * click to show hints.
 * 
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child
 * points to the next node of a pre-order traversal.
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
    void flatten(TreeNode* node, TreeNode * &last){
        if(!node){
            return;
        }
        
        last = node;
        flatten(node->left, last);
        last->right = node->right;
        if(node->left){
            node->right = node->left;
            node->left = NULL;
        }
        flatten(node->right, last);
    }
    
    void flatten(TreeNode* root) {
        TreeNode *last = NULL;
        flatten(root, last);
    }
};
