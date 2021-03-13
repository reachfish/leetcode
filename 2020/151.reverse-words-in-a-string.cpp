/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (23.44%)
 * Likes:    1547
 * Dislikes: 3174
 * Total Accepted:    506.9K
 * Total Submissions: 2.1M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string s, reverse the order of the words.
 *
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space.
 *
 * Return a string of the words in reverse order concatenated by a single
 * space.
 *
 * Note that s may contain leading or trailing spaces or multiple spaces
 * between two words. The returned string should only have a single space
 * separating the words. Do not include any extra spaces.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 *
 *
 * Example 4:
 *
 *
 * Input: s = "  Bob    Loves  Alice   "
 * Output: "Alice Loves Bob"
 *
 *
 * Example 5:
 *
 *
 * Input: s = "Alice does not even like bob"
 * Output: "bob like even not does Alice"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s contains English letters (upper-case and lower-case), digits, and spaces '
 * '.
 * There is at least one word in s.
 *
 *
 *
 * Follow up: Could you solve it in-place with O(1) extra space?
 *
 */

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      std::swap(s[i], s[j]);
    }

    int ws = -1;
    int len = 0;
    for (int i = 0; i <= s.size(); i++) {
      if (i == s.size() || s[i] == ' ') {
        if (ws >= 0) {
          if (len > 0) {
            s[len++] = ' ';
          }
          for (int j = ws, k = i - 1; j < k; j++, k--) {
            std::swap(s[j], s[k]);
          }
          for (int j = ws; j < i; j++) {
            s[len++] = s[j];
          }
          ws = -1;
        }
      } else if (ws < 0) {
        ws = i;
      }
    }

    s.resize(len);

    return s;
  }
};
// @lc code=end
