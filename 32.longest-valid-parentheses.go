/*
 * @lc app=leetcode id=32 lang=golang
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (25.68%)
 * Total Accepted:    195.6K
 * Total Submissions: 761.6K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
func Max(x, y int) int {
	if x >= y {
		return x
	} else {
		return y
	}
}

func countOn(dp []int, index int) int {
	if index < 0 {
		return 0
	} else {
		return dp[index]
	}
}

func longestValidParentheses(s string) int {
	ret := 0
	dp := make([]int, len(s))
	for i := 0; i<len(s); i++ {
		count := 0
		ch := s[i]
		if ch == ')' {
			if i >= 1 && s[i-1] == '(' {
				count = countOn(dp, i - 2) + 2
			}
			prevCount := countOn(dp, i-1)
			j := i - prevCount - 1
			if j >= 0 && s[j] == '(' {
				count = Max(count, prevCount + countOn(dp, j-1) + 2)
			}
			ret = Max(count, ret)
		}
		dp[i] = count
	}

	return ret
}
