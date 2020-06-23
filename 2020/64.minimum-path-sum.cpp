/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (53.74%)
 * Likes:    2931
 * Dislikes: 60
 * Total Accepted:    412.8K
 * Total Submissions: 767.2K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        vector<int> sum(n);
        sum[0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            sum[j] = sum[j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            sum[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                sum[j] = std::min(sum[j - 1], sum[j]) + grid[i][j];
            }
        }

        return sum[n - 1];
    }
};
// @lc code=end
