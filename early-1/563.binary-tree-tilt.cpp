/*
 * [563] Binary Tree Tilt
 *
 * https://leetcode.com/problems/binary-tree-tilt
 *
 * Easy (47.01%)
 * Total Accepted:    9734
 * Total Submissions: 20704
 * Testcase Example:  '[1,2,3]'
 *
 * Given a binary tree, return the tilt of the whole tree.
 * 
 * The tilt of a tree node is defined as the absolute difference between the
 * sum of all left subtree node values and the sum of all right subtree node
 * values. Null node has tilt 0.
 * 
 * The tilt of the whole tree is defined as the sum of all nodes' tilt.
 * 
 * Example:
 * 
 * Input: 
 * ⁠        1
 * ⁠      /   \
 * ⁠     2     3
 * Output: 1
 * Explanation: 
 * Tilt of node 2 : 0
 * Tilt of node 3 : 0
 * Tilt of node 1 : |2-3| = 1
 * Tilt of binary tree : 0 + 0 + 1 = 1
 * 
 * 
 * 
 * Note:
 * 
 * The sum of node values in any subtree won't exceed the range of 32-bit
 * integer. 
 * All the tilt values won't exceed the range of 32-bit integer.
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
    int findTilt(TreeNode* p, int &count) {
        if(!p){
            count = 0;
            return 0;
        }
        
        int countLeft;
        int countRight;
        
        int tilt1 = findTilt(p->left, countLeft);
        int tilt2 = findTilt(p->right, countRight);
        count = countLeft + countRight + p->val;
        
        int diff = countLeft - countRight;
        if(diff<0){
            diff = -diff;
        }
        
        return tilt1 + tilt2 + diff; 
    }
    
    int findTilt(TreeNode* root) {
        int count = 0;
        return findTilt(root, count);
    }
};
