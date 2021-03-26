/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (32.16%)
 * Likes:    2846
 * Dislikes: 745
 * Total Accepted:    451.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 0
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: n = 1
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 5 * 10^6
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int countPrimes(int n) {
    if (n < 2) {
      return 0;
    }

    vector<int> primes;
    for (int i = 2; i < n; i++) {
      bool is_prime = true;
      int m = sqrt(i);
      for (auto p : primes) {
        if (i % p == 0) {
          is_prime = false;
          break;
        }

        if (p >= m) {
          break;
        }
      }

      if (is_prime) {
        primes.push_back(i);
      }
    }

    return primes.size();
  }
};
// @lc code=end
