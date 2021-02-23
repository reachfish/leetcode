/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (38.02%)
 * Likes:    1769
 * Dislikes: 3598
 * Total Accepted:    796.4K
 * Total Submissions: 2.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string s, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int alphanum(char c) {
    if (c >= '0' && c <= '9') {
      return c;
    }
    if (c >= 'A' && c <= 'Z') {
      return c;
    }
    if (c >= 'a' && c <= 'z') {
      return c + 'A' - 'a';
    }

    return -1;
  }

  bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    int l, r;
    for (;;) {
      for (;;) {
        if (i >= j) {
          return true;
        }

        if ((l = alphanum(s[i])) > 0) {
          break;
        }

        ++i;
      }

      for (;;) {
        if (i >= j) {
          return true;
        }

        if ((r = alphanum(s[j])) > 0) {
          break;
        }

        --j;
      }

      if (l == r) {
        ++i;
        --j;
      } else {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
