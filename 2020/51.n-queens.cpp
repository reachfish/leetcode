/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (45.60%)
 * Likes:    1778
 * Dislikes: 70
 * Total Accepted:    197.4K
 * Total Submissions: 432.8K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
		if (n <= 0) {
			return {};
		}

		vector<vector<string>> result;
		vector<bool> column(n, false);
		vector<bool> pie(2*n - 1, false);
		vector<bool> na(2*n - 1, false);
		vector<string> s(n, std::string(n, '.'));
		iterate(result, s, column, pie, na, 0);
		return result;
    }

	void iterate(vector<vector<string>>& result,
				 vector<string>& s,
				 vector<bool>& column,
				 vector<bool>& pie,
				 vector<bool>& na,
				 int i) {
		int n = s.size();
		if (i == n) {
			result.push_back(s);
			return;
		}

		for (int j=0;j<n;j++) {
			int k = n - 1 + i - j;
			int m = i + j;
			if (column[j] || pie[k] || na[m]) {
				continue;
			}
			column[j] = pie[k] = na[m] = true;
			s[i][j] = 'Q';
			iterate(result, s, column, pie, na, i + 1);
			column[j] = pie[k] = na[m] = false;
			s[i][j] = '.';
		}
	}
};
// @lc code=end
