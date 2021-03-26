/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (40.40%)
 * Likes:    1932
 * Dislikes: 460
 * Total Accepted:    351.2K
 * Total Submissions: 866K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings s and t are isomorphic if the characters in s can be replaced to
 * get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character, but a character may map to itself.
 *
 *
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * t.length == s.length
 * s and t consist of any valid ascii character.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    int m1[256] = {0};
    int m2[256] = {0};

    if (s.size() != t.size()) {
      return false;
    }

    for (int i = 0; i < s.size(); i++) {
      auto& c1 = m1[s[i]];
      if (c1 != 0) {
        if (c1 != t[i]) {
          return false;
        }
      } else {
        c1 = t[i];
      }

      auto& c2 = m2[t[i]];
      if (c2 != 0) {
        if (c2 != s[i]) {
          return false;
        }
      } else {
        c2 = s[i];
      }
    }

    return true;
  }
};
// @lc code=end
