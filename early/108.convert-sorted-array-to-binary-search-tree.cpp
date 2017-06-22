/*
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
 *
 * Easy (41.70%)
 * Total Accepted:    123809
 * Total Submissions: 296914
 * Testcase Example:  '[]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
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
    TreeNode* toBST(vector<int>& nums, int i, int j){
        if(i>j) return NULL;
        
        int mid = i + (j-i+1)/2;
        TreeNode *p = new TreeNode(nums[mid]);
        p->left = toBST(nums, i, mid - 1);
        p->right = toBST(nums, mid+1, j);
        
        return p;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size()-1);
    }
};
