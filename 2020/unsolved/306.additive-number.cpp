/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 *
 * https://leetcode.com/problems/additive-number/description/
 *
 * algorithms
 * Medium (29.61%)
 * Likes:    526
 * Dislikes: 514
 * Total Accepted:    59.5K
 * Total Submissions: 199.8K
 * Testcase Example:  '"112358"'
 *
 * Additive number is a string whose digits can form additive sequence.
 *
 * A valid additive sequence should contain at least three numbers. Except for
 * the first two numbers, each subsequent number in the sequence must be the
 * sum of the preceding two.
 *
 * Given a string containing only digits '0'-'9', write a function to determine
 * if it's an additive number.
 *
 * Note: Numbers in the additive sequence cannot have leading zeros, so
 * sequence 1, 2, 03 or 1, 02, 3 is invalid.
 *
 *
 * Example 1:
 *
 *
 * Input: "112358"
 * Output: true
 * Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5,
 * 8.
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 *
 *
 * Example 2:
 *
 *
 * Input: "199100199"
 * Output: true
 * Explanation: The additive sequence is: 1, 99, 100, 199. 
 * 1 + 99 = 100, 99 + 100 = 199
 *
 *
 *
 * Constraints:
 *
 *
 * num consists only of digits '0'-'9'.
 * 1 <= num.length <= 35
 *
 *
 * Follow up:
 * How would you handle overflow for very large input integers?
 *
 */

// @lc code=start
class Solution {
 public:
  bool isAdditiveNumber(string num) {
    const int kTLen = num.size();
    std::string counter(num.size());
    for (int len1 = 1; len1 <= kTLen / 2; len1++) {
      for (int k = 0; k < len1; k++) {
        buffer[k] = num[len1 - k - 1];
      }
      for (int len2 = 1; len1 + len2 <= kTLen / 2; len2++) {
        int start = len1;
        int blen = len1;
        add(buffer, blen);
        if (match(num, buffer, len1, len2)) {
          return true;
        }
      }
    }

    return false;
  }
};
// @lc code=end
