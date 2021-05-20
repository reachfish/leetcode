/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (52.30%)
 * Likes:    1596
 * Dislikes: 103
 * Total Accepted:    202.3K
 * Total Submissions: 386.6K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string s which consists of lowercase or uppercase letters, return
 * the length of the longest palindrome that can be built with those letters.
 *
 * Letters are case sensitive, for example, "Aa" is not considered a palindrome
 * here.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abccccdd"
 * Output: 7
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a"
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: s = "bb"
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2000
 * s consists of lowercase and/or uppercase English letters only.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int longestPalindrome(string s) {
    int count[26 * 2] = {0};
    for (auto c : s) {
      int i = c - 'a';
      if (i < 0) {
        i += 'a' - 'A' + 26;
      }

      count[i]++;
    }

    bool odd = false;
    int total = 0;
    for (auto n : count) {
      if (n & 1) {
        odd = true;
        total -= 1;
      }
      total += n;
    }

    if (odd) {
      total++;
    }

    return total;
  }
};
// @lc code=end
