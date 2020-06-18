/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (33.62%)
 * Likes:    2240
 * Dislikes: 558
 * Total Accepted:    359.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return {};
		}
		enum DIRECT { L, R, U, D };
		int m = matrix.size();
		int n = matrix[0].size();
		int i = 0, j = 0;
		int left_most = 0, right_most = n - 1;
		int up_most = 0, down_most = m - 1;
		vector<int> result(m * n);
		DIRECT d = R;
		for (int k=0; k<m*n; k++) {
			result[k] = matrix[i][j];
			switch (d ) {
				case R: {
					if (j < right_most) {
						++j;
					} else {
						d = D;
						++i;
						++up_most;
					}

					break;
				};
				case D: {
					if (i < down_most) {
						++i;
					} else {
						d = L;
						--j;
						--right_most;
					}
					break;
				}
				case L: {
					if (j > left_most) {
						--j;
					} else {
						d = U;
						--i;
						--down_most;
					}
					break;
				}
				case U: {
					if (i > up_most) {
						--i;
					} else {
						d = R;
						++j;
						++left_most;
					}
					break;
				}
				default: {
				}
			}
		}

		return result;
    }
};
// @lc code=end
