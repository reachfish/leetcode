/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (40.31%)
 * Likes:    1488
 * Dislikes: 209
 * Total Accepted:    150.3K
 * Total Submissions: 364.2K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
  '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2,
 * col2).
 *
 * Implement the NumMatrix class:
 *
 *
 * NumMatrix(int[][] matrix) initializes the object with the integer matrix
 * matrix.
 * int sumRegion(int row1, int col1, int row2, int col2) returns the sum of the
 * elements of the matrix array inside the rectangle defined by its upper left
 * corner (row1, col1) and lower right corner (row2, col2).
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
 * [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1,
 * 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
 * Output
 * [null, 8, 11, 12]
 *
 * Explanation
 * NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1,
 * 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
 * numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red
 * rectangele).
 * numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green
 * rectangele).
 * numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue
 * rectangele).
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * -10^5 <= matrix[i][j] <= 10^5
 * 0 <= row1 <= row2 < m
 * 0 <= col1 <= col2 < n
 * At most 10^4 calls will be made to sumRegion.
 *
 *
 */

// @lc code=start
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    sum_ = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
      int s = 0;
      for (int j = 0; j < n; j++) {
        s += matrix[i][j];
        sum_[i + 1][j + 1] = sum_[i][j + 1] + s;
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    ++row2;
    ++col2;
    int a = sum_[row2][col2];
    int b = sum_[row1][col2];
    int c = sum_[row2][col1];
    int d = sum_[row1][col1];
    return a + d - b - c;
  }

  vector<vector<int>> sum_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
