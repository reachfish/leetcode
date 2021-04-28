/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (44.57%)
 * Likes:    3218
 * Dislikes: 56
 * Total Accepted:    222.9K
 * Total Submissions: 480K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an m x n integers matrix, return the length of the longest increasing
 * path in matrix.
 *
 * From each cell, you can either move in four directions: left, right, up, or
 * down. You may not move diagonally or move outside the boundary (i.e.,
 * wrap-around is not allowed).
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [[1]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * 0 <= matrix[i][j] <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix.empty() ? 0 : matrix[0].size();

    if (n == 0) {
      return 0;
    }

    struct Pos {
      int i;
      int j;
    };

    vector<vector<int>> len(m, vector<int>(n, 0));
    queue<Pos> postition;
    int max_len = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (Update(matrix, len, i, j, &max_len)) {
          postition.push({i, j});
        }
      }
    }

    const int kDirs[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!postition.empty()) {
      auto pos = postition.front();
      postition.pop();
      for (auto dir : kDirs) {
        int ni = pos.i + dir[0];
        int nj = pos.j + dir[1];
        if (Update(matrix, len, ni, nj, &max_len)) {
          postition.push({ni, nj});
        }
      }
    }

    return max_len;
  }

  bool Update(const vector<vector<int>>& matrix, vector<vector<int>>& len,
              int i, int j, int* max_len) {
    int m = matrix.size();
    int n = matrix[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || len[i][j] > 0) {
      return false;
    }

    static const int kDirs[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int sub_len = 0;
    for (auto dir : kDirs) {
      int ni = i + dir[0];
      int nj = j + dir[1];
      if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
          matrix[i][j] < matrix[ni][nj]) {
        if (len[ni][nj] == 0) {
          return false;
        }
        if (len[ni][nj] > sub_len) {
          sub_len = len[ni][nj];
        }
      }
    }

    len[i][j] = 1 + sub_len;
    if (*max_len < len[i][j]) {
      *max_len = len[i][j];
    }

    return true;
  }
};
// @lc code=end
