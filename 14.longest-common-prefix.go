/*
 * @lc app=leetcode id=14 lang=golang
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.68%)
 * Total Accepted:    483.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
func longestCommonPrefix(strs []string) string {
	if len(strs) < 1 {
		return ""
	}

	var c byte
	t := -1

	outfor:
	for i := 0 ; ; t, i = i, i+1{
		for j, str := range(strs) {
			if i == len(str) {
				break outfor
			}
			if j == 0 {
				c = str[i]
			} else if c != str[i] {
				break outfor
			}
		}
	}
	if t >= 0 {
		return strs[0][0:t+1]
	} else {
		return ""
	}
}
