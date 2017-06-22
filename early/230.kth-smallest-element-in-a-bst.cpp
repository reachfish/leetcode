/*
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst
 *
 * Medium (43.32%)
 * Total Accepted:    97488
 * Total Submissions: 225024
 * Testcase Example:  '[1]\n1'
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 * 
 * Note: 
 * You may assume k is always valid, 1 ? k ? BST's total elements.
 * 
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to
 * find the kth smallest frequently? How would you optimize the kthSmallest
 * routine?
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
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
    void find(TreeNode* p, int k, int &order, int &result){
        if(!p || order >= k) { return; }
        find(p->left, k, order, result);
        order++;
        if(order==k){
            result = p->val;
            return;
        }
        find(p->right, k, order, result);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int order = 0;
        int result = 0;
        find(root, k, order, result);
        
        return result;
    }
};
