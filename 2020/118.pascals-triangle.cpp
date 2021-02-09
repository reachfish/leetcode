/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (54.51%)
 * Likes:    2195
 * Dislikes: 130
 * Total Accepted:    457.2K
 * Total Submissions: 836.7K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0) { return {}; }

        vector<vector<int>> result(numRows);
        result[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            const auto& last_row = result[i - 1];
            auto& row            = result[i];
            row.resize(i + 1);
            row[0] = row[i] = 1;
            for (int j = 1; j < i; j++) { row[j] = last_row[j - 1] + last_row[j]; }
        }

        return result;
    }
};
// @lc code=end
