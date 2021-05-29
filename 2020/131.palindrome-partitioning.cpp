/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (52.86%)
 * Likes:    3535
 * Dislikes: 115
 * Total Accepted:    318.4K
 * Total Submissions: 597.1K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome. Return all possible palindrome partitioning of s.
 *
 * A palindrome string is a string that reads the same backward as forward.
 *
 *
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;

    vector<vector<bool>> parlind(s.size(), vector<bool>(s.size(), false));
    for (int i = 0; i < s.size(); i++) {
      parlind[i][i] = true;
      if (i && s[i] == s[i - 1]) {
        parlind[i - 1][i] = true;
      }
    }

    bool odd = true;
    bool even = true;
    for (int len = 3; len <= s.size() && (odd || even); len++) {
      int half = len >> 1;
      if (odd && (len & 1)) {
        odd = false;
        for (int i = half; i < s.size() - half; i++) {
          int b = i - half;
          int e = i + half;
          if (s[b] == s[e] && parlind[b + 1][e - 1]) {
            parlind[b][e] = odd = true;
          }
        }
      }

      if (even && !(len & 1)) {
        even = false;
        for (int i = half; i <= s.size() - half; i++) {
          int b = i - half;
          int e = i + half - 1;
          if (s[b] == s[e] && parlind[b + 1][e - 1]) {
            parlind[b][e] = even = true;
          }
        }
      }
    }

    vector<string> part;
    part.reserve(s.size());
    dp(s, parlind, 0, part, result);

    return result;
  }

  void dp(const std::string& s, const vector<vector<bool>>& parlind, int i,
          vector<string>& part, vector<vector<string>>& result) {
    if (i == s.size()) {
      result.push_back(part);
      return;
    }

    for (int j = i; j < s.size(); j++) {
      if (parlind[i][j]) {
        part.push_back(s.substr(i, j - i + 1));
        dp(s, parlind, j + 1, part, result);
        part.pop_back();
      }
    }
  }
};
// @lc code=end
