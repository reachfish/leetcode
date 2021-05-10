/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (54.06%)
 * Likes:    2943
 * Dislikes: 142
 * Total Accepted:    734.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '"leetcode"'
 *
 * Given a string s, return the first non-repeating character in it and return
 * its index. If it does not exist, return -1.
 *
 *
 * Example 1:
 * Input: s = "leetcode"
 * Output: 0
 * Example 2:
 * Input: s = "loveleetcode"
 * Output: 2
 * Example 3:
 * Input: s = "aabb"
 * Output: -1
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int firstUniqChar(string s) {
    int count[26] = {0};
    for (auto c : s) {
      count[c - 'a']++;
    }

    for (int i = 0; i < s.size(); i++) {
      if (count[s[i] - 'a'] == 1) {
        return i;
      }
    }

    return -1;
  }
};
// @lc code=end
