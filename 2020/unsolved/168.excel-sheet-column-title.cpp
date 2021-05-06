/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (31.64%)
 * Likes:    1606
 * Dislikes: 294
 * Total Accepted:    248.1K
 * Total Submissions: 780.1K
 * Testcase Example:  '1'
 *
 * Given an integer columnNumber, return its corresponding column title as it
 * appears in an Excel sheet.
 *
 * For example:
 *
 *
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 * ...
 *
 *
 *
 * Example 1:
 *
 *
 * Input: columnNumber = 1
 * Output: "A"
 *
 *
 * Example 2:
 *
 *
 * Input: columnNumber = 28
 * Output: "AB"
 *
 *
 * Example 3:
 *
 *
 * Input: columnNumber = 701
 * Output: "ZY"
 *
 *
 * Example 4:
 *
 *
 * Input: columnNumber = 2147483647
 * Output: "FXSHRXW"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= columnNumber <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string s;
    while (columnNumber) {
      char c = columnNumber % 26 + 'A' - 1;
      s.push_back(c);
      columnNumber = (columnNumber - (c - 'A' + 1)) / 26;
    }

    std::reverse(s.begin(), s.end());

    return s;
  }
};
// @lc code=end
