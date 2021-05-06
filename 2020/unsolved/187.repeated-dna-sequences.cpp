/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (41.30%)
 * Likes:    1146
 * Dislikes: 332
 * Total Accepted:    204.4K
 * Total Submissions: 491.9K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * The DNA sequence is composed of a series of nucleotides abbreviated as 'A',
 * 'C', 'G', and 'T'.
 *
 *
 * For example, "ACGAATTCCG" is a DNA sequence.
 *
 *
 * When studying DNA, it is useful to identify repeated sequences within the
 * DNA.
 *
 * Given a string s that represents a DNA sequence, return all the
 * 10-letter-long sequences (substrings) that occur more than once in a DNA
 * molecule. You may return the answer in any order.
 *
 *
 * Example 1:
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * Output: ["AAAAACCCCC","CCCCCAAAAA"]
 * Example 2:
 * Input: s = "AAAAAAAAAAAAA"
 * Output: ["AAAAAAAAAA"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is either 'A', 'C', 'G', or 'T'.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    map<string, int> m;
    for (int i = 0; i <= int(s.size()) - 10; i++) {
      m[s.substr(i, 10)]++;
    }
    vector<string> v;
    for (const auto& it : m) {
      if (it.second > 1) {
        v.push_back(it.first);
      }
    }

    return v;
  }
};
// @lc code=end
