/*
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees
 *
 * algorithms
 * Medium (25.92%)
 * Total Accepted:    2.8K
 * Total Submissions: 9.5K
 * Testcase Example:  '[2,1,1]'
 *
 * 
 * Given a binary tree, return all duplicate subtrees. For each kind of
 * duplicate subtrees, you only need to return the root node of any one of
 * them. 
 * 
 * 
 * Two trees are duplicate if they have the same structure with same node
 * values.
 * 
 * 
 * Example 1: 
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   2   4
 * ⁠      /
 * ⁠     4
 * 
 * The following are two duplicate subtrees:
 * 
 * ⁠     2
 * ⁠    /
 * ⁠   4
 * 
 * and
 * 
 * ⁠   4
 * 
 * Therefore, you need to return above trees' root in the form of a list.
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		map<string, int> m;
		vector<TreeNode*> res;

		postOrder(root, m, res);

		return res;		
    }

	string postOrder(TreeNode* p, map<string, int>& m, vector<TreeNode*>& res){
		if(!p){
			return "#";
		}

		string s = to_string(p->val) + "," + postOrder(p->left, m, res) + "," + postOrder(p->right, m, res);
		m[s]++;
		if(m[s]==2){
			res.push_back(p);
		}

		return s;
	}
};
