/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (51.96%)
 * Likes:    1230
 * Dislikes: 217
 * Total Accepted:    353.3K
 * Total Submissions: 678.8K
 * Testcase Example:  '3'
 *
 * Given an integer rowIndex, return the rowIndex^th row of the Pascal's
 * triangle.
 * 
 * Notice that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 * 
 * Example 1:
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 * Example 2:
 * Input: rowIndex = 0
 * Output: [1]
 * Example 3:
 * Input: rowIndex = 1
 * Output: [1,1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= rowIndex <= 33
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) { return {}; }

        vector<int> row(rowIndex + 1);
        row[0] = row[rowIndex] = 1;
        for (int i = 1; i <= rowIndex / 2; i++) {
            int value = int(int64_t(row[i - 1]) * (rowIndex - i + 1) / i);
            row[i] = row[rowIndex - i] = value;
        }

        return row;
    }
};
// @lc code=end
