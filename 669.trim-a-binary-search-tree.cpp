/*
 * [669] Trim a Binary Search Tree
 *
 * https://leetcode.com/problems/trim-a-binary-search-tree
 *
 * algorithms
 * Easy (58.11%)
 * Total Accepted:    12.6K
 * Total Submissions: 21.6K
 * Testcase Example:  '[1,0,2]\n1\n2'
 *
 * 
 * Given a binary search tree and the lowest and highest boundaries as L and R,
 * trim the tree so that all its elements lies in [L, R] (R >= L). You might
 * need to change the root of the tree, so the result should return the new
 * root of the trimmed binary search tree.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 0   2
 * 
 * ⁠ L = 1
 * ⁠ R = 2
 * 
 * Output: 
 * ⁠   1
 * ⁠     \
 * ⁠      2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * ⁠   3
 * ⁠  / \
 * ⁠ 0   4
 * ⁠  \
 * ⁠   2
 * ⁠  /
 * ⁠ 1
 * 
 * ⁠ L = 1
 * ⁠ R = 3
 * 
 * Output: 
 * ⁠     3
 * ⁠    / 
 * ⁠  2   
 * ⁠ /
 * ⁠1
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

#define LEFT 1
#define RIGHT 2

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
		TreeNode *r = NULL;

		helper(root, L, R, NULL, LEFT, r);

		return r;
    }

private:
	void helper(TreeNode* p, int L, int R, TreeNode* parent, int leftright, TreeNode* &root){
		if(!p) { 
			return; 
		}

		if(p->val < L){
			helper(p->right, L, R, parent, leftright, root);
		}
		else if(p->val > R){
			helper(p->left, L, R, parent, leftright, root);
		}
		else{

			if(parent){
				if(leftright == LEFT){
					parent->left = p;
				}
				else{
					parent->right = p;
				}
			}
			else{
				root = p;
			}

			TreeNode* left = p->left;
			TreeNode* right = p->right;

			p->left = NULL;
			p->right = NULL;

			helper(left, L, R, p, LEFT,  root);
			helper(right, L, R, p, RIGHT,  root);
		}
	}
};
