/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (57.05%)
 * Likes:    479
 * Dislikes: 147
 * Total Accepted:    131K
 * Total Submissions: 229.5K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
		if (n <= 0) {
			return 1;
		}

		vector<bool> column(n, false);
		vector<bool> pie(2*n - 1, false);
		vector<bool> na(2*n - 1, false);
		return iterate(column, pie, na, n, 0);
    }

	int iterate(vector<bool>& column,
				vector<bool>& pie,
				vector<bool>& na,
				int n,
				int i) {
		if (i == n) {
			return 1;
		}

		int count = 0;
		for (int j=0; j<n; j++) {
			int k = i + j;
			int m = n - 1 + i - j;
			if (column[j] || pie[k] || na[m]) {
				continue;
			}

			column[j] = pie[k] = na[m] = true;
			count += iterate(column, pie, na, n, i + 1);
			column[j] = pie[k] = na[m] = false;
		}

		return count;
	}
};
// @lc code=end
