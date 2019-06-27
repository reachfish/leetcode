/*
 * @lc app=leetcode id=20 lang=golang
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.69%)
 * Total Accepted:    616.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
func isValid(s string) bool {
	stack := make([]rune, 0)

	topIsChar := func(ch rune) bool {
		topIdx := len(stack) - 1
		if topIdx >= 0 && stack[topIdx] == ch {
			stack = stack[:topIdx]
			return true
		} else {
			return false
		}
	}

	for _, ch := range(s) {
		switch ch {
		case '{', '[', '(':
			stack = append(stack, ch)
		case '}':
			if !topIsChar('{') {
				return false
			}
		case ']':
			if !topIsChar('[') {
				return false
			}
		case ')':
			if !topIsChar('(') {
				return false
			}
		default:
			return false
		}
	}

	return len(stack) == 0
}
