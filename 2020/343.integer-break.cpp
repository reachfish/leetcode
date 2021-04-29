/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (51.44%)
 * Likes:    1584
 * Dislikes: 263
 * Total Accepted:    131.1K
 * Total Submissions: 254.8K
 * Testcase Example:  '2'
 *
 * Given an integer n, break it into the sum of k positive integers, where k >=
 * 2, and maximize the product of those integers.
 *
 * Return the maximum product you can get.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 58
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int integerBreak(int n) {
    if (n == 2) {
      return 1;
    }

    if (n == 3) {
      return 2;
    }

    int r = 1;
    int c3 = n / 3;
    switch (n % 3) {
      case 1:
        c3--;
        r = 4;
        break;
      case 2:
        r = 2;
        break;
    }

    for (int i = 0; i < c3; i++) {
      r *= 3;
    }

    return r;
  }
};
// @lc code=end
