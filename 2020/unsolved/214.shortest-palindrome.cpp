/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (30.56%)
 * Likes:    1575
 * Dislikes: 150
 * Total Accepted:    113.8K
 * Total Submissions: 370K
 * Testcase Example:  '"aacecaaa"'
 *
 * You are given a string s. You can convert s to a palindrome by adding
 * characters in front of it.
 *
 * Return the shortest palindrome you can find by performing this
 * transformation.
 *
 *
 * Example 1:
 * Input: s = "aacecaaa"
 * Output: "aaacecaaa"
 * Example 2:
 * Input: s = "abcd"
 * Output: "dcbabcd"
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s consists of lowercase English letters only.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string shortestPalindrome(string s) {
    uint32_t sz = s.size();
    int i = sz / 2 - 1;
    int j = i + 1;
    for (int j = i + 1; i >= 0; i--, j++) {
    }
  }
};
// @lc code=end
