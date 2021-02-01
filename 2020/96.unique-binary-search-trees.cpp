/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (54.24%)
 * Likes:    4242
 * Dislikes: 158
 * Total Accepted:    345.4K
 * Total Submissions: 636.5K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of structurally unique BST's (binary
 * search trees) which has exactly n nodes of unique values from 1 to n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 19
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) { return 1; }

        int dp[n + 1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int count = 0;
            for (int k = 0; k < i; k++) { count += dp[k] * dp[i - k - 1]; }
            dp[i] = count;
        }

        return dp[n];
    }
};
// @lc code=end
