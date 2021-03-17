/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (56.78%)
 * Likes:    1586
 * Dislikes: 194
 * Total Accepted:    366.9K
 * Total Submissions: 643.8K
 * Testcase Example:  '"A"'
 *
 * Given a string columnTitle that represents the column title as appear in an
 * Excel sheet, return its corresponding column number.
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
 * Input: columnTitle = "A"
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: columnTitle = "AB"
 * Output: 28
 *
 *
 * Example 3:
 *
 *
 * Input: columnTitle = "ZY"
 * Output: 701
 *
 *
 * Example 4:
 *
 *
 * Input: columnTitle = "FXSHRXW"
 * Output: 2147483647
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= columnTitle.length <= 7
 * columnTitle consists only of uppercase English letters.
 * columnTitle is in the range ["A", "FXSHRXW"].
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int n = 0;
    for (auto c : columnTitle) {
      n = n * 26 - 'A' + 1 + c;
    }

    return n;
  }
};
// @lc code=end
