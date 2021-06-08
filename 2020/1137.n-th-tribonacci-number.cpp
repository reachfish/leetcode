/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 *
 * https://leetcode.com/problems/n-th-tribonacci-number/description/
 *
 * algorithms
 * Easy (55.75%)
 * Likes:    597
 * Dislikes: 58
 * Total Accepted:    79.5K
 * Total Submissions: 143K
 * Testcase Example:  '4'
 *
 * The Tribonacci sequence Tn is defined as follows: 
 *
 * T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 *
 * Given n, return the value of Tn.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: 4
 * Explanation:
 * T_3 = 0 + 1 + 1 = 2
 * T_4 = 1 + 1 + 2 = 4
 *
 *
 * Example 2:
 *
 *
 * Input: n = 25
 * Output: 1389537
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 37
 * The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31
 * - 1.
 *
 */

// @lc code=start
class Solution {
 public:
  int tribonacci(int n) {
    int nums[] = {0, 1, 1, 0};
    for (int i = 3; i <= n; i++) {
      nums[i & 3] = nums[(i - 1) & 3] + nums[(i - 2) & 3] + nums[(i - 3) & 3];
    }

    return nums[n & 3];
  }
};
// @lc code=end
