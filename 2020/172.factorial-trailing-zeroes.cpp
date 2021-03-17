/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (38.43%)
 * Likes:    1216
 * Dislikes: 1361
 * Total Accepted:    249.7K
 * Total Submissions: 645.9K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Follow up: Could you write a solution that works in logarithmic time
 * complexity?
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 0
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int trailingZeroes(int n) {
    int count = 0;
    for (int power = 5, k = n / power; k; power *= 5, k = n / power) {
      count += k;
    }

    return count;
  }
};
// @lc code=end
