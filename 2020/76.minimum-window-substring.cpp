/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (35.78%)
 * Likes:    6205
 * Dislikes: 421
 * Total Accepted:    508.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t, return the minimum window in s which will contain
 * all the characters in t. If there is no such window in s that covers all
 * characters in t, return the empty string "".
 *
 * Note that If there is such a window, it is guaranteed that there will always
 * be only one unique minimum window in s.
 *
 *
 * Example 1:
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Example 2:
 * Input: s = "a", t = "a"
 * Output: "a"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 10^5
 * s and t consist of English letters.
 *
 *
 *
 * Follow up: Could you find an algorithm that runs in O(n) time?
 */

// @lc code=start
class Solution {
 public:
  string minWindow(string s, string t) {
    map<char, int> chars;
    for (auto c : t) {
      chars[c]++;
    }

    string r;
    int start = 0;
    int found = 0;
    for (int i = 0; i < s.size(); i++) {
      auto c = s[i];
      auto it = chars.find(c);
      if (it == chars.end()) {
        continue;
      }

      auto& count = it->second;
      count--;

      if (count == 0) {
        found++;
      }

      if (found != chars.size()) {
        continue;
      }

      for (; start <= i; start++) {
        auto c = s[start];
        auto it = chars.find(c);
        if (it == chars.end()) {
          continue;
        }

        auto& count = it->second;
        if (count < 0) {
          ++count;
          continue;
        } else {
          break;
        }
      }

      int len = i - start + 1;
      if (r.empty() || len < r.size()) {
        r = s.substr(start, len);
      }
    }

    return r;
  }
};
// @lc code=end
