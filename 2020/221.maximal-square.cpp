/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (38.90%)
 * Likes:    4397
 * Dislikes: 104
 * Total Accepted:    346.9K
 * Total Submissions: 878K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given an m x n binary matrix filled with 0's and 1's, find the largest
 * square containing only 1's and return its area.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [["0","1"],["1","0"]]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [["0"]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 300
 * matrix[i][j] is '0' or '1'.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  struct Area {
    int w = 0;
    int h = 0;
  };

  int maximalSquare(vector<vector<char>>& matrix) {
    int col = matrix.empty() ? 0 : matrix[0].size();
    if (col == 0) {
      return 0;
    }

    int max_edge = 0;
    vector<vector<int>> edge(2, vector<int>(col + 1, 0));
    int index = 0;
    for (const auto& row : matrix) {
      int last_index = index;
      index = 1 - index;
      for (int i = 1; i <= col; i++) {
        if (row[i - 1] == '0') {
          edge[index][i] = 0;
        } else {
          int e = std::min(edge[index][i - 1], std::min(edge[last_index][i - 1],
                                                        edge[last_index][i])) +
                  1;
          edge[index][i] = e;
          if (e > max_edge) {
            max_edge = e;
          }
        }
      }
    }

    return max_edge * max_edge;
  }
};
// @lc code=end
