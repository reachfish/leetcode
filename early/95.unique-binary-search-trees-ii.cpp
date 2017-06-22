/*
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii
 *
 * Medium (31.14%)
 * Total Accepted:    81224
 * Total Submissions: 260860
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1...n.
 * 
 * 
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 * 
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
    
    vector<TreeNode*> generate(int i, int j){
        vector<TreeNode*> res;
        if(i>j) { res.push_back(NULL); }
    
        for(int k=i;k<=j;k++){
            vector<TreeNode*> left = generate(i, k-1);
            vector<TreeNode*> right = generate(k+1, j);
            for(int r=0;r<left.size();r++){
                for(int s=0;s<right.size();s++){
                    TreeNode* root = new TreeNode(k);
                    root->left = left[r];
                    root->right = right[s];
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n<=0) return vector<TreeNode*>();
        return generate(1, n);
    }
};
