/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 *
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (49.03%)
 * Likes:    571
 * Dislikes: 1011
 * Total Accepted:    88K
 * Total Submissions: 179.3K
 * Testcase Example:  '2'
 *
 * Given an integer n, return the count of all numbers with unique digits, x,
 * where 0 <= x < 10^n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 91
 * Explanation: The answer should be the total numbers in the range of 0 ≤ x <
 * 100, excluding 11,22,33,44,55,66,77,88,99
 *
 *
 * Example 2:
 *
 *
 * Input: n = 0
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 8
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n <= 0) {
      return 1;
    }

    int count = 10;
    int last = 9;
    int d = 9;
    for (int i = 2; i <= n; i++) {
      last *= d;
      count += last;
      if (--d == 0) {
        break;
      }
    }

    return count;
  }
};
// @lc code=end
