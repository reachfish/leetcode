/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (52.13%)
 * Likes:    1020
 * Dislikes: 79
 * Total Accepted:    108.2K
 * Total Submissions: 206K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, return the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. If no such
 * two words exist, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] consists only of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int maxProduct(vector<string>& words) {
    vector<int> dict(words.size());
    for (int i = 0; i < words.size(); i++) {
      int num = 0;
      for (auto c : words[i]) {
        num |= 1 << (c - 'a');
      }
      dict[i] = num;
    }

    int max = 0;
    for (int i = 0; i < words.size(); i++) {
      for (int j = i + 1; j < words.size(); j++) {
        if (!(dict[i] & dict[j])) {
          int len = words[i].size() * words[j].size();
          if (len > max) {
            max = len;
          }
        }
      }
    }

    return max;
  }
};
// @lc code=end
