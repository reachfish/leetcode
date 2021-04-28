/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (34.48%)
 * Likes:    1767
 * Dislikes: 174
 * Total Accepted:    115.9K
 * Total Submissions: 331.4K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * Given a list of unique words, return all the pairs of the distinct indices
 * (i, j) in the given list, so that the concatenation of the two words
 * words[i] + words[j] is a palindrome.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]]
 * Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["bat","tab","cat"]
 * Output: [[0,1],[1,0]]
 * Explanation: The palindromes are ["battab","tabbat"]
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["a",""]
 * Output: [[0,1],[1,0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 5000
 * 0 <= words[i].length <= 300
 * words[i] consists of lower-case English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> result;
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words.size(); j++) {
        if (i == j) {
          continue;
        }

        if (isPalindrome(words[i], words[j])) {
          result.push_back({i, j});
        }
      }
    }

    return result;
  }

  bool isPalindrome(const std::string& s, const std::string& t) const {
    int sz = s.size();
    int tz = t.size();

#define CHAR(idx) (idx < sz ? s[idx] : t[idx - sz])

    for (int i = 0, j = sz + tz - 1; i < j; i++, j--) {
      if (CHAR(i) != CHAR(j)) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
