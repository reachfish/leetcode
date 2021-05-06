/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (42.26%)
 * Likes:    1238
 * Dislikes: 194
 * Total Accepted:    270.8K
 * Total Submissions: 640.7K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 *
 * Follow up: Do not use any built-in library function such as sqrt.
 *
 *
 * Example 1:
 * Input: num = 16
 * Output: true
 * Example 2:
 * Input: num = 14
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= num <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isPerfectSquare(int num) {
    if (num == 1) {
      return true;
    }

    for (int i = num / 2; i >= 1; i--) {
      int d = i * i - num;
      if (d == 0) {
        return true;
      }
      if (d < 0) {
        break;
      }
    }

    return false;
  }
};
// @lc code=end
