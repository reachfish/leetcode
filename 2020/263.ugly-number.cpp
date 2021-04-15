/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 *
 * https://leetcode.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (41.71%)
 * Likes:    742
 * Dislikes: 779
 * Total Accepted:    237.3K
 * Total Submissions: 569.1K
 * Testcase Example:  '6'
 *
 * Given an integer n, return true if n is an ugly number.
 *
 * Ugly number is a positive number whose prime factors only include 2, 3,
 * and/or 5.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 6
 * Output: true
 * Explanation: 6 = 2 × 3
 *
 * Example 2:
 *
 *
 * Input: n = 8
 * Output: true
 * Explanation: 8 = 2 × 2 × 2
 *
 *
 * Example 3:
 *
 *
 * Input: n = 14
 * Output: false
 * Explanation: 14 is not ugly since it includes another prime factor 7.
 *
 *
 * Example 4:
 *
 *
 * Input: n = 1
 * Output: true
 * Explanation: 1 is typically treated as an ugly number.
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isUgly(int n) {
    if (n <= 0) {
      return false;
    }

    for (auto p : {2, 3, 5}) {
      while (n > 1) {
        int k = n / p;
        if (p * k != n) {
          break;
        }
        n = k;
      }
    }

    return n == 1;
  }
};
// @lc code=end
