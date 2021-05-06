/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 *
 * https://leetcode.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (38.94%)
 * Likes:    2436
 * Dislikes: 184
 * Total Accepted:    119K
 * Total Submissions: 301.9K
 * Testcase Example:  '"bcabc"'
 *
 * Given a string s, remove duplicate letters so that every letter appears once
 * and only once. You must make sure your result is the smallest in
 * lexicographical order among all possible results.
 *
 * Note: This question is the same as 1081:
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 *
 *
 * Example 1:
 *
 *
 * Input: s = "bcabc"
 * Output: "abc"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbacdcbc"
 * Output: "acdb"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string removeDuplicateLetters(string s) {
    vector<int> pos[26];
    for (int i = 0; i < s.size(); i++) {
      pos[s[i] - 'a'].push_back(i);
    }

    set<int> select;
    int max = -1;
    for (int i = 0; i < 26; i++) {
      const auto& vpos = pos[i];
      if (vpos.empty()) {
        continue;
      }

      auto it = upper_bound(pos[i].begin(), pos[i].end(), max);
    }

    string r;
    return r;
  }
};
// @lc code=end
