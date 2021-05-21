/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (48.64%)
 * Likes:    1805
 * Dislikes: 390
 * Total Accepted:    298.7K
 * Total Submissions: 611.9K
 * Testcase Example:  '"11"\n"123"'
 *
 * Given two non-negative integers, num1 and num2 represented as string, return
 * the sum of num1 and num2 as a string.
 *
 * You must solve the problem without using any built-in library for handling
 * large integers (such as BigInteger). You must also not convert the inputs to
 * integers directly.
 *
 *
 * Example 1:
 *
 *
 * Input: num1 = "11", num2 = "123"
 * Output: "134"
 *
 *
 * Example 2:
 *
 *
 * Input: num1 = "456", num2 = "77"
 * Output: "533"
 *
 *
 * Example 3:
 *
 *
 * Input: num1 = "0", num2 = "0"
 * Output: "0"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num1.length, num2.length <= 10^4
 * num1 and num2 consist of only digits.
 * num1 and num2 don't have any leading zeros except for the zero itself.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string addStrings(string num1, string num2) {
    std::string s;
    s.reserve(std::max(num1.size(), num2.size()) + 1);

    int flag = 0;
    for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0;
         i--, j--) {
      int num =
          flag + (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0);
      if (num >= 10) {
        num -= 10;
        flag = 1;
      } else {
        flag = 0;
      }
      s.push_back(char('0' + num));
    }

    if (flag) {
      s.push_back(char('0' + flag));
    }

    std::reverse(s.begin(), s.end());

    return s;
  }
};
// @lc code=end
