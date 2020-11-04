/*
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers
 *
 * Medium (36.14%)
 * Total Accepted:    109516
 * Total Submissions: 303039
 * Testcase Example:  '[]'
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number
 * 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * For example,
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * 
 * 
 * 
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * 
 * 
 * Return the sum = 12 + 13 = 25.
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
    int sumTree(TreeNode* p, int s){
        if(!p) { return 0; }
        int val = s * 10 + p->val;
        if(!p->left && !p->right) { return val; }
        
        int sum = 0;
        if(p->left){
            sum += sumTree(p->left, val); 
        }
        if(p->right){
            sum += sumTree(p->right, val);
        }
        
        return sum;
    }
    
    int sumNumbers(TreeNode* root) {
        return sumTree(root, 0);
    }
};
