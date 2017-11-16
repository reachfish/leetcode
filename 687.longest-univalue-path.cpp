/*
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path
 *
 * algorithms
 * Easy (33.08%)
 * Total Accepted:    8.7K
 * Total Submissions: 26.2K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 * 
 * Note: The length of path between two nodes is represented by the number of
 * edges between them.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * 
 * 
 * Output:
 * 
 * 2
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * 
 * 
 * Output:
 * 
 * 2
 * 
 * 
 * 
 * Note:
 * The given binary tree has not more than 10000 nodes.  The height of the tree
 * is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root) {
		int max = 0;
		int len = 0;

		helper(root, max, len);

		return max;
    }

	void helper(TreeNode* p, int &max, int &len){
		len = 0;
		if(!p){
			return;
		}

		int llen = 0, rlen = 0;
		int cross = 0;

		TreeNode* left = p->left;
		if(left){
			helper(left, max, llen);
			if(left->val == p->val){
				llen++;
				if(len < llen){
					len = llen;
				}
				cross += llen;
			}
		}

		TreeNode* right = p->right;
		if(right){
			helper(right, max, rlen);
			if(right->val == p->val){
				rlen++;
				if(len < rlen){
					len = rlen;
				}
				cross += rlen;
			}
		}

		if(max < len){
			max = len;
		}
		if(max < cross){
			max = cross;
		}
	}
};
