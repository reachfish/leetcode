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
    for (int m = 1; m <= num.size() / 2; m++) {
      if (m > 1 && num[0] == '0') {
        break;
      }

      for (int n = 1; std::max(m, n) <= num.size() - m - n; n++) {
        if (n > 1 && num[m] == '0') {
          break;
        }

        if (isAdd(num, m, n)) {
          return true;
        }
      }
    }
    return false;
  }

  bool isAdd(const std::string& num, int m, int n) {
    std::string a = num.substr(0, m);
    std::string b = num.substr(m, n);
    uint32_t total_len = m + n;
    for (;;) {
      std::string c = addNum(a, b);
      total_len += c.size();
      if (total_len > num.size()) {
        return false;
      }

      if (num.compare(total_len - c.size(), c.size(), c) != 0) {
        return false;
      }

      if (total_len == num.size()) {
        return true;
      }

      a.swap(b);
      b.swap(c);
    }

    return false;
  }

  std::string addNum(const std::string& a, const std::string& b) {
    std::string s;
    s.reserve(std::max(a.size(), b.size()) + 1);
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0) {
      int c = (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0) + carry;
      if (c >= 10) {
        c -= 10;
        carry = 1;
      } else {
        carry = 0;
      }
      s.push_back(c + '0');
      i--;
      j--;
    }

    if (carry > 0) {
      s.push_back(carry + '0');
    }

    std::reverse(s.begin(), s.end());

    return s;
  }
};
// @lc code=end
