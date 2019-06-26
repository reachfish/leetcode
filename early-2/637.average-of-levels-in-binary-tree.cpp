/*
 * [637] Average of Levels in Binary Tree
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree
 *
 * Easy (60.79%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 * 
 * Example 1:
 * 
 * Input:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on
 * level 2 is 11. Hence return [3, 14.5, 11].
 * 
 * 
 * 
 * Note:
 * 
 * The range of node's value is in the range of 32-bit signed integer.
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
	void helper(TreeNode* p, int deep, vector<double>& res, vector<int> &cnt){
		if(!p) { return ; }

		if(deep==res.size()){
			res.push_back(0);
			cnt.push_back(0);
		}

		res[deep] += p->val;
		cnt[deep]++;

		helper(p->left, deep + 1, res, cnt);
		helper(p->right, deep + 1, res, cnt);
	}

    vector<double> averageOfLevels(TreeNode* root) {
		vector<double> res;
		vector<int> cnt;

		helper(root, 0, res, cnt);        

		for(int i=0; i<res.size(); i++){
			res[i] /= (double)(cnt[i]);
		}

		return res;
    }
};
