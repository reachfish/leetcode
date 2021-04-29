/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (45.31%)
 * Likes:    1014
 * Dislikes: 1475
 * Total Accepted:    276K
 * Total Submissions: 609K
 * Testcase Example:  '"hello"'
 *
 * Given a string s, reverse only all the vowels in the string and return it.
 *
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
 * cases.
 *
 *
 * Example 1:
 * Input: s = "hello"
 * Output: "holle"
 * Example 2:
 * Input: s = "leetcode"
 * Output: "leotcede"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consist of printable ASCII characters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string reverseVowels(string s) {
    constexpr int kMask = (1 << ('a' - 'a')) | (1 << ('e' - 'a')) |
                          (1 << ('i' - 'a')) | (1 << ('o' - 'a')) |
                          (1 << ('u' - 'a'));

    auto is_vowel = [](char c) -> bool {
      return (c >= 'a' && c <= 'z' && (kMask & (1 << (c - 'a'))) != 0) ||
             (c >= 'A' && c <= 'Z' && (kMask & (1 << (c - 'A'))) != 0);
    };

    for (int i = 0, j = s.size() - 1; true;) {
      while (i < j && !is_vowel(s[i])) {
        i++;
      }
      while (i < j && !is_vowel(s[j])) {
        j--;
      }

      if (i < j) {
        std::swap(s[i++], s[j--]);
      } else {
        break;
      }
    }

    return s;
  }
};
// @lc code=end
