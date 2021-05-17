/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (43.71%)
 * Likes:    2591
 * Dislikes: 269
 * Total Accepted:    123K
 * Total Submissions: 280.9K
 * Testcase Example:  '"aaabb"\n3'
 *
 * Given a string s and an integer k, return the length of the longest
 * substring of s such that the frequency of each character in this substring
 * is greater than or equal to k.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aaabb", k = 3
 * Output: 3
 * Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "ababbc", k = 2
 * Output: 5
 * Explanation: The longest substring is "ababb", as 'a' is repeated 2 times
 * and 'b' is repeated 3 times.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only lowercase English letters.
 * 1 <= k <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int longestSubstring(string s, int k) { return helper(s, 0, s.size(), k); }

  int helper(const std::string& s, int start, int end, int k) {
    int size = end - start;
    if (k > size) {
      return 0;
    }

    if (k == 1) {
      return size;
    }

    unordered_map<char, int> counter;
    for (int i = start; i < end; i++) {
      counter[s[i]]++;
    }

    unordered_set<char> bads;
    for (const auto& it : counter) {
      if (it.second < k) {
        bads.insert(it.first);
      }
    }

    if (bads.empty()) {
      return size;
    }

    int max_count = 0;
    int ss = -1;
    for (int i = start; i <= end; i++) {
      if (i == end || bads.count(s[i])) {
        if (ss != -1) {
          max_count = std::max(max_count, helper(s, ss, i, k));
        }
        ss = -1;
      } else if (ss == -1) {
        ss = i;
      }
    }

    return max_count;
  }
};
// @lc code=end
