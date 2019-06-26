/*
 * [617] Merge Two Binary Trees
 *
 * https://leetcode.com/problems/merge-two-binary-trees
 *
 * Easy (72.31%)
 * Total Accepted:    6700
 * Total Submissions: 9263
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * 
 * Given two binary trees and imagine that when you put one of them to cover
 * the other, some nodes of the two trees are overlapped while the others are
 * not. 
 * 
 * 
 * You need to merge them into a new binary tree. The merge rule is that if two
 * nodes overlap, then sum node values up as the new value of the merged node.
 * Otherwise, the NOT null node will be used as the node of new tree.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * Tree 1                     Tree 2                  
 * ⁠         1                         2                             
 * ⁠        / \                       / \                            
 * ⁠       3   2                     1   3                        
 * ⁠      /                           \   \                      
 * ⁠     5                             4   7                  
 * Output: 
 * Merged tree:
 * 3
 * / \
 * 4   5
 * / \   \ 
 * 5   4   7
 * 
 * 
 * 
 * 
 * Note:
 * The merging process must start from the root nodes of both trees.
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) { return NULL; }
        TreeNode *left1 = NULL, *right1 = NULL, *left2 = NULL, *right2 = NULL;
        int val1 = 0, val2 = 0;
        if(t1){
            left1 = t1->left;
            right1 = t1->right;
            val1 = t1->val;
        }
        if(t2){
            left2 = t2->left;
            right2 = t2->right;
            val2 = t2->val;
        }
        TreeNode *p = new TreeNode(val1 + val2);
        p->left = mergeTrees(left1, left2);
        p->right = mergeTrees(right1, right2);
        
        return p;
    }
};
