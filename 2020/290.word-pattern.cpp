/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (38.28%)
 * Likes:    1820
 * Dislikes: 217
 * Total Accepted:    252.4K
 * Total Submissions: 656.2K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string s, find if s follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in s.
 *
 *
 * Example 1:
 *
 *
 * Input: pattern = "abba", s = "dog cat cat dog"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: pattern = "abba", s = "dog cat cat fish"
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: pattern = "aaaa", s = "dog cat cat dog"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: pattern = "abba", s = "dog dog dog dog"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= pattern.length <= 300
 * pattern contains only lower-case English letters.
 * 1 <= s.length <= 3000
 * s contains only lower-case English letters and spaces ' '.
 * s does not contain any leading or trailing spaces.
 * All the words in s are separated by a single space.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    if (s.size() < pattern.size()) {
      return false;
    }

    int8_t next = 1;
    int8_t m[26] = {0};
    for (auto& c : pattern) {
      auto& n = m[c - 'a'];
      if (n == 0) {
        n = next++;
      }
      c = (char)n;
    }

    next = 1;
    std::map<std::string, int8_t> sm;
    int wc = 0;
    for (int i = 0, start = 0; i <= s.size(); i++) {
      if (i == s.size() || s[i] == ' ') {
        auto& n = sm[s.substr(start, i - start)];
        if (n == 0) {
          n = next++;
        }

        if (wc >= pattern.size() || pattern[wc] != n) {
          return false;
        }

        start = i + 1;
        wc++;
      }
    }

    return wc == pattern.size();
  }
};
// @lc code=end
