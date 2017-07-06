/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses
 *
 * Medium (44.00%)
 * Total Accepted:    145535
 * Total Submissions: 330794
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
class Solution {
public:
	
	void helper(vector<string>& res, string& s, int left, int right){
		if(left==0 && right==0){
			res.push_back(s);
			return;
		}

		int i = s.size() - left - right;

		if(left > 0){
			s[i] = '(';
			helper(res, s, left - 1, right);
		}

		if(right > 0 && right > left){
			s[i] = ')';
			helper(res, s, left, right - 1);
		}
	}

    vector<string> generateParenthesis(int n) {
		if(n<=0) { return vector<string>(); }        

		vector<string> res;
		string s(2*n, '0');
		helper(res, s, n, n);

		return res;
    }
};
