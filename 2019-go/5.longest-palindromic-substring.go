/*
 * @lc app=leetcode id=5 lang=golang
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.44%)
 * Total Accepted:    580.2K
 * Total Submissions: 2.1M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
func longestPalindrome(s string) string {
	n := len(s)
	if n == 0 {
		return ""
	}

	maxn := 0
	result := ""
	dp := make([][]bool, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]bool, n)
		dp[i][i] = true
	}

	isPalindromic := func(left, right int) bool {
		if left < 0 || right >= n || s[left] != s[right] {
			return false
		}
		if left + 1 < right - 1 && !dp[left+1][right-1] {
			return false
		}
		dp[left][right] = true
		count := right - left + 1
		if count > maxn {
			maxn = count
			result = s[left:right+1]
		}
		return true
	}

	for i := 0; i < n; i++ {
		for count := 1; count <= n; count += 2 {
			half := count>>1
			left, right := i - half, i + half
			if !isPalindromic(left, right) {
				break
			}
		}
		for count := 2; count <= n; count += 2 {
			half := count>>1
			left, right := i - half + 1, i + half
			if !isPalindromic(left, right) {
				break
			}
		}
	}

	return result
}
