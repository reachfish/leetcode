/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 *
 * https://leetcode.com/problems/long-pressed-name/description/
 *
 * algorithms
 * Easy (37.14%)
 * Likes:    1049
 * Dislikes: 189
 * Total Accepted:    67.7K
 * Total Submissions: 184.9K
 * Testcase Example:  '"alex"\n"aaleex"'
 *
 * Your friend is typing his name into a keyboard. Sometimes, when typing a
 * character c, the key might get long pressed, and the character will be typed
 * 1 or more times.
 *
 * You examine the typed characters of the keyboard. Return True if it is
 * possible that it was your friends name, with some characters (possibly none)
 * being long pressed.
 *
 *
 * Example 1:
 *
 *
 * Input: name = "alex", typed = "aaleex"
 * Output: true
 * Explanation: 'a' and 'e' in 'alex' were long pressed.
 *
 *
 * Example 2:
 *
 *
 * Input: name = "saeed", typed = "ssaaedd"
 * Output: false
 * Explanation: 'e' must have been pressed twice, but it wasn't in the typed
 * output.
 *
 *
 * Example 3:
 *
 *
 * Input: name = "leelee", typed = "lleeelee"
 * Output: true
 *
 *
 * Example 4:
 *
 *
 * Input: name = "laiden", typed = "laiden"
 * Output: true
 * Explanation: It's not necessary to long press any character.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= name.length <= 1000
 * 1 <= typed.length <= 1000
 * name and typed contain only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    if (name.size() > typed.size()) {
      return false;
    }

    int i = 0;
    int j = 0;
    for (;;) {
      int ns = i;
      while (i < name.size()) {
        if (name[i] != name[ns]) {
          break;
        }
        i++;
      }

      int ts = j;
      while (j < typed.size()) {
        if (typed[j] != typed[ts]) {
          break;
        }
        j++;
      }

      int nlen = i - ns;
      int tlen = j - ts;
      if (nlen > tlen) {
        return false;
      }

      if (nlen == 0) {
        return tlen == 0;
      }

      if (name[ns] != typed[ts]) {
        return false;
      }
    }

    return false;
  }
};
// @lc code=end
