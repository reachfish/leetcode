/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (61.73%)
 * Likes:    4983
 * Dislikes: 260
 * Total Accepted:    537.5K
 * Total Submissions: 870.8K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
		if (n <= 0) {
			return {};
		}

		string buf(2*n, 'a');
		vector<string> result;
		result.reserve((2)
		iterate(result, buf, n, 0, 0);
		return result;
    }

	void iterate(vector<string>& result, string& buf, int n, int left_side, int right_side) {
		int total = left_side + right_side;
		if (total == (n<<1)) {
			result.push_back(buf);
			return;
		}

		if (left_side < n) {
			buf[total] = '(';
			iterate(result, buf, n, left_side + 1, right_side);
		}
		if (left_side > right_side) {
			buf[total] = ')';
			iterate(result, buf, n, left_side, right_side + 1);
		}
	}
};
// @lc code=end
