/*
 * @lc app=leetcode id=22 lang=golang
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (55.42%)
 * Total Accepted:    351.4K
 * Total Submissions: 633.9K
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
func generateParenthesis(n int) []string {
	if n <= 0 {
		return []string{""}
	}

	seq := make([]byte, 2 * n)
	result := make([]string, 0)
	result = iterate(result, seq, 0, 0, n)

	return result
}

func iterate(result []string, seq []byte, left int, right int, n int) []string {
	if left > n || right > n || left < right {
		return result
	}

	if left + right == n*2 {
		result = append(result, string(seq[:]))
		return result
	}

	idx := left + right
	seq[idx] = '('
	result = iterate(result, seq, left + 1, right, n)
	seq[idx] = ')'
	result = iterate(result, seq, left, right + 1, n)

	return result
}

