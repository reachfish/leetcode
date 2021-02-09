/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (45.57%)
 * Likes:    2614
 * Dislikes: 296
 * Total Accepted:    283.7K
 * Total Submissions: 621.3K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle array, return the minimum path sum from top to bottom.
 * 
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
 * above).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: triangle = [[-10]]
 * Output: -10
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 <= triangle[i][j] <= 10^4
 * 
 * 
 * 
 * Follow up: Could you do this using only O(n) extra space, where n is the
 * total number of rows in the triangle?
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle.back().empty()) { return 0; }

        vector<int> step(triangle.back().size(), 0);
        for (const auto& line : triangle) {
            int t = line.size() - 1;
            if (t != 0) { step[t] = step[t - 1] + line[t]; }
            for (int i = t - 1; i > 0; i--) { step[i] = std::min(step[i - 1], step[i]) + line[i]; }
            step[0] += line[0];
        }

        int m = step[0];
        for (auto v : step) {
            if (m > v) { m = v; }
        }

        return m;
    }
};
// @lc code=end
