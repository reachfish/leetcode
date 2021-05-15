/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (49.62%)
 * Likes:    2467
 * Dislikes: 239
 * Total Accepted:    297.1K
 * Total Submissions: 598.8K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * Given two strings s and t, check if s is a subsequence of t.
 *
 * A subsequence of a string is a new string that is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (i.e., "ace" is a
 * subsequence of "abcde" while "aec" is not).
 *
 *
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * s and t consist only of lowercase English letters.
 *
 *
 *
 * Follow up: If there are lots of incoming s, say s1, s2, ..., sk where k >=
 * 10^9, and you want to check one by one to see if t has its subsequence. In
 * this scenario, how would you change your code?
 */

// @lc code=start
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    uint32_t k = 0;
    for (auto c : t) {
      if (k == s.size()) {
        break;
      }
      if (c == s[k]) {
        k++;
      }
    }

    return k == s.size();
  }
};
// @lc code=end
