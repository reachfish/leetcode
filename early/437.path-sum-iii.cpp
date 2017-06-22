/*
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii
 *
 * Easy (39.50%)
 * Total Accepted:    27202
 * Total Submissions: 68874
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 * 
 * Find the number of paths that sum to a given value.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 * 
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 * 
 * Example:
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * Return 3. The paths that sum to 8 are:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
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
    void pathSum(TreeNode* p, int sum, vector<int> &v, int &total){
        if(!p){
            return;
        }
       
        int size = v.size();
        
        v.push_back(0);
        for(int i=0;i<v.size();i++){
            v[i] += p->val;
            if(v[i]==sum){
                total++;
            }
        }
        
        pathSum(p->left, sum, v, total);
        pathSum(p->right, sum, v, total);
        
        v.erase(v.begin()+size, v.end());
        for(int i=0;i<v.size();i++){
            v[i] -= p->val;
        }
    }
    
    int pathSum(TreeNode* root, int sum) {
        int total = 0;
        vector<int> v;
        pathSum(root, sum, v, total);
        return total;
    }
};
