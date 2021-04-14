/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (44.26%)
 * Likes:    4606
 * Dislikes: 87
 * Total Accepted:    441.7K
 * Total Submissions: 973.3K
 * Testcase Example:
 '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n'
 + '5'
 *
 * Write an efficient algorithm that searches for a target value in an m x n
 * integer matrix. The matrix has the following properties:
 *
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 5
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 20
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= n, m <= 300
 * -10^9 <= matix[i][j] <= 10^9
 * All the integers in each row are sorted in ascending order.
 * All the integers in each column are sorted in ascending order.
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
      return false;
    }

    return searchMx(matrix, target, 0, matrix.size() - 1, 0,
                    matrix[0].size() - 1);
  }

  bool searchMx(const vector<vector<int>>& matrix, int target, int rstart,
                int rend, int cstart, int cend) {
    if (rstart > rend || cstart > cend || target < matrix[rstart][cstart] ||
        target > matrix[rend][cend]) {
      return false;
    }

    int rmid = (rstart + rend) / 2;
    int cmid = (cstart + cend) / 2;
    int val = matrix[rmid][cmid];
    if (target == val) {
      return true;
    }

    if (searchLine(matrix, target, rmid, cstart, cend, true) ||
        searchLine(matrix, target, cmid, rstart, rend, false)) {
      return true;
    }

    if (searchMx(matrix, target, rstart, rmid - 1, cmid + 1, cend) ||
        searchMx(matrix, target, rmid + 1, rend, cstart, cmid - 1)) {
      return true;
    }

    if (target < val) {
      return searchMx(matrix, target, rstart, rmid - 1, cstart, cmid - 1);
    } else {
      return searchMx(matrix, target, rmid + 1, rend, cmid + 1, cend);
    }
  }

  bool searchLine(const vector<vector<int>>& matrix, int target, int line,
                  int start, int end, bool is_row) {
    for (; start <= end;) {
      int mid = (start + end) / 2;
      int val = is_row ? matrix[line][mid] : matrix[mid][line];
      if (target == val) {
        return true;
      } else if (target < val) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }

    return false;
  }
};
// @lc code=end
