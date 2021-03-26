/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (39.60%)
 * Likes:    1326
 * Dislikes: 142
 * Total Accepted:    168.9K
 * Total Submissions: 425.9K
 * Testcase Example:  '5\n7'
 *
 * Given two integers left and right that represent the range [left, right],
 * return the bitwise AND of all numbers in this range, inclusive.
 *
 *
 * Example 1:
 *
 *
 * Input: left = 5, right = 7
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: left = 0, right = 0
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: left = 1, right = 2147483647
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= left <= right <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    int value = 0;
    for (int i = 30; i >= 0; i--) {
      int l = left & (1 << i);
      int r = right & (1 << i);
      if (l != r) {
        break;
      }

      value |= l;
    }

    return value;
  }
};
// @lc code=end
