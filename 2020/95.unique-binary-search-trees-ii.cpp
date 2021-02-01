/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (42.22%)
 * Likes:    2797
 * Dislikes: 196
 * Total Accepted:    218.5K
 * Total Submissions: 516.9K
 * Testcase Example:  '3'
 *
 * Given an integer n, return all the structurally unique BST's (binary search
 * trees), which has exactly n nodes of unique values from 1 to n. Return the
 * answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output:
 * [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) { return dp(1, n); }

    vector<TreeNode*> dp(int i, int j) {
        if (i > j) { return {nullptr}; }

        vector<TreeNode*> result;
        for (int k = i; k <= j; k++) {
            auto left  = dp(i, k - 1);
            auto right = dp(k + 1, j);
            for (int l = 0; l < left.size(); l++) {
                for (int r = 0; r < right.size(); r++) {
                    result.push_back(new TreeNode(k, left[l], right[r]));
                }
            }
        }

        return result;
    }
};
// @lc code=end
