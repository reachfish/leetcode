/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 *
 * https://leetcode.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (47.19%)
 * Likes:    2545
 * Dislikes: 117
 * Total Accepted:    298.8K
 * Total Submissions: 633.1K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * Given two strings s and t, return true if they are equal when both are typed
 * into empty text editors. '#' means a backspace character.
 *
 * Note that after backspacing an empty text, the text will continue empty.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ab#c", t = "ad#c"
 * Output: true
 * Explanation: Both s and t become "ac".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "ab##", t = "c#d#"
 * Output: true
 * Explanation: Both s and t become "".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a##c", t = "#a#c"
 * Output: true
 * Explanation: Both s and t become "c".
 *
 *
 * Example 4:
 *
 *
 * Input: s = "a#c", t = "b"
 * Output: false
 * Explanation: s becomes "c" while t becomes "b".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 200
 * s and t only contain lowercase letters and '#' characters.
 *
 *
 *
 * Follow up: Can you solve it in O(n) time and O(1) space?
 *
 */

// @lc code=start
class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    int i = s.size() - 1;
    int j = t.size() - 1;

    for (;;) {
      i = backSearch(s, i);
      j = backSearch(t, j);
      if (i < 0) {
        return j < 0;
      }

      if (j < 0) {
        return false;
      }

      if (s[i] != t[j]) {
        return false;
      }

      i--;
      j--;
    }

    return false;
  }

  int backSearch(const std::string& s, int i) {
    int backspace = 0;
    for (; i >= 0; i--) {
      if (s[i] == '#') {
        backspace++;
      } else if (backspace-- == 0) {
        break;
      }
    }

    return i;
  }
};
// @lc code=end
