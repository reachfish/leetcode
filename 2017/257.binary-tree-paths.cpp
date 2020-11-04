/*
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths
 *
 * Easy (37.51%)
 * Total Accepted:    108111
 * Total Submissions: 288243
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * 
 * For example, given the following binary tree:
 * 
 * 
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 
 * 
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
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
    void findPaths(TreeNode* p, string s, vector<string> &paths){
        if(!p){ return; }
        
        size_t len = s.size();
        
        if(s.empty()){
            s = to_string(p->val);
        }
        else{
            s += "->" + to_string(p->val);
        }
        
        if(!p->left && !p->right){
            paths.push_back(s);
        }
        
        findPaths(p->left, s, paths);
        findPaths(p->right, s, paths);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        findPaths(root, "", paths);
        
        return paths;
    }
};
