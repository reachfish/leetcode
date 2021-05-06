/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 *
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (38.57%)
 * Likes:    1128
 * Dislikes: 81
 * Total Accepted:    54.7K
 * Total Submissions: 141.8K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * Given an m x n matrix matrix and an integer k, return the max sum of a
 * rectangle in the matrix such that its sum is no larger than k.
 *
 * It is guaranteed that there will be a rectangle with a sum no larger than
 * k.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,0,1],[0,-2,3]], k = 2
 * Output: 2
 * Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2,
 * and 2 is the max number no larger than k (k = 2).
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[2,2,-1]], k = 3
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -100 <= matrix[i][j] <= 100
 * -10^5 <= k <= 10^5
 *
 *
 *
 * Follow up: What if the number of rows is much larger than the number of
 * columns?
 *
 */

// @lc code=start
class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix.empty() ? 0 : matrix[0].size();
    if (n == 0) {
      return 0;
    }

    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      int s = 0;
      for (int j = 1; j <= n; j++) {
        s += matrix[i - 1][j - 1];
        sum[i][j] = s + sum[i - 1][j];
      }
    }

    int max_sum = INT_MIN;
    for (int i1 = 1; i1 <= m; i1++) {
      for (int i2 = i1; i2 <= m; i2++) {
        for (int j1 = 1; j1 <= n; j1++) {
          for (int j2 = j1; j2 <= n; j2++) {
            int ilow = i1 - 1;
            int jlow = j1 - 1;
            int rect_sum =
                sum[i2][j2] + sum[ilow][jlow] - sum[ilow][j2] - sum[i2][jlow];
            if (rect_sum == k) {
              return k;
            }
            if (rect_sum < k && rect_sum > max_sum) {
              max_sum = rect_sum;
            }
          }
        }
      }
    }

    return max_sum;
  }
};
// @lc code=end
