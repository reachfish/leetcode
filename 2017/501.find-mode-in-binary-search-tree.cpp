/*
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree
 *
 * Easy (38.01%)
 * Total Accepted:    15026
 * Total Submissions: 39538
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * 
 * Assume a BST is defined as follows:
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * return [2].
 * 
 * 
 * Note:
 * If a tree has more than one mode, you can return them in any order.
 * 
 * 
 * Follow up:
 * Could you do that without using any extra space? (Assume that the implicit
 * stack space incurred due to recursion does not count).
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

    void find(TreeNode* node, TreeNode* &pre, int &count, int &maxCount, vector<int>& res){
        if(!node){
            return;
        }
        
        find(node->left, pre, count, maxCount, res);
        
        if(!pre||pre->val==node->val){
            count++;
        }
        else{
            count = 1;
        }
        
        if(count >= maxCount){
            if(count > maxCount){
                maxCount = count;
                res.clear();
            }
            res.push_back(node->val);
        }
        
        pre = node;
        
        find(node->right, pre, count, maxCount, res);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        TreeNode* pre = NULL;
        int count = 0, maxCount = 0;
        find(root, pre, count, maxCount, res);
        
        return res;
    }
};
