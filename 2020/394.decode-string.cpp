/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (53.14%)
 * Likes:    5023
 * Dislikes: 238
 * Total Accepted:    328.1K
 * Total Submissions: 615.9K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 *
 *
 * Example 1:
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * Example 2:
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * Example 3:
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * Example 4:
 * Input: s = "abc3[cd]xyz"
 * Output: "abccdcdcdxyz"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string decodeString(string s) {
    stack<string> subs_stk;
    stack<int> times_stk;
    times_stk.push(0);
    subs_stk.push("");
    int times = 0;
    for (auto c : s) {
      if (c == '[') {
        times_stk.push(times);
        subs_stk.push("");
        times = 0;
      } else if (c == ']') {
        auto sub = subs_stk.top();
        int times = times_stk.top();

        subs_stk.pop();
        times_stk.pop();

        auto& ss = subs_stk.top();
        ss.reserve(ss.size() + sub.size() * times);
        for (int i = 0; i < times; i++) {
          ss += sub;
        }
      } else if (c >= '0' && c <= '9') {
        times = 10 * times + c - '0';
      } else {
        subs_stk.top().push_back(c);
      }
    }

    return subs_stk.top();
  }
};
// @lc code=end
