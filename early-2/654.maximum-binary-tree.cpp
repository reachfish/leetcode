/*
 * [654] Maximum Binary Tree
 *
 * https://leetcode.com/problems/maximum-binary-tree
 *
 * algorithms
 * Medium (76.82%)
 * Total Accepted:    7.2K
 * Total Submissions: 9.9K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 
 * Given an integer array with no duplicates. A maximum tree building on this
 * array is defined as follow:
 * 
 * The root is the maximum number in the array. 
 * The left subtree is the maximum tree constructed from left part subarray
 * divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray
 * divided by the maximum number. 
 * 
 * 
 * 
 * 
 * Construct the maximum tree by the given array and output the root node of
 * this tree.
 * 
 * 
 * Example 1:
 * 
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 * 
 * ⁠     6
 * ⁠   /   \
 * ⁠  3     5
 * ⁠   \    / 
 * ⁠    2  0   
 * ⁠      \
 * ⁠       1
 * 
 * 
 * 
 * Note:
 * 
 * The size of the given array will be in the range [1,1000].
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return construct(nums, 0, nums.size() - 1);        
    }

	TreeNode* construct(vector<int>& nums, int begin, int end){
		if(begin > end){
			return nullptr;
		}

		int max = nums[begin];
		int maxIdx = begin;

		for(int i=begin; i<= end; i++){
			if(nums[i] > max){
				max = nums[i];
				maxIdx = i;
			}
		}

		TreeNode* node = new TreeNode(max);
		node->left = construct(nums, begin, maxIdx - 1);
		node->right = construct(nums, maxIdx + 1, end);

		return node;
	}
};
