/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (53.51%)
 * Likes:    884
 * Dislikes: 241
 * Total Accepted:    262.4K
 * Total Submissions: 490.2K
 * Testcase Example:  '"a"\n"b"'
 *
 * Given two stings ransomNote and magazine, return true if ransomNote can be
 * constructed from magazine and false otherwise.
 *
 * Each letter in magazine can only be used once in ransomNote.
 *
 *
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote and magazine consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int count[26] = {0};
    for (auto c : magazine) {
      count[c - 'a']++;
    }

    for (auto c : ransomNote) {
      if (--count[c - 'a'] < 0) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
