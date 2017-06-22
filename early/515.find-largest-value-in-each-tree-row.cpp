/*
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row
 *
 * Medium (54.75%)
 * Total Accepted:    15737
 * Total Submissions: 28746
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * You need to find the largest value in each row of a binary tree.
 * 
 * Example:
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode* > que;
        if(!root){
            return ret;
        }
        
        que.push(root);
        que.push(NULL);
        int max = INT_MIN;
        while(!que.empty()){
            TreeNode *p = que.front();
            que.pop();
            if(p==NULL){
                if(que.empty()){
                    break;
                }
                ret.push_back(max);
                max = INT_MIN;
                que.push(NULL);
            }
            else{
                max = max < p->val ? p->val : max;
                if(p->left){
                    que.push(p->left);
                }
                if(p->right){
                    que.push(p->right);
                }
            }
        }
        
        ret.push_back(max);
        
        return ret;
    }
};
