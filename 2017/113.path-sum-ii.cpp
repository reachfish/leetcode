/*
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii
 *
 * Medium (32.99%)
 * Total Accepted:    125474
 * Total Submissions: 380325
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 
 * return
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
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
    void pathSumRec(TreeNode *root, int cur, vector<int>& path, vector<vector<int> >& paths){
        if(!root){
            return;
        }
        
        path.push_back(root->val);
        cur -= root->val;
        
        if(cur == 0 && !root->left && !root->right){
            paths.push_back(path);
        }
        
        pathSumRec(root->left, cur, path, paths);
        pathSumRec(root->right, cur, path, paths);
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        
        pathSumRec(root, sum, path, paths);
        
        return paths;
    }
};
