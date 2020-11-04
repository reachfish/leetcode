/*
 * @lc app=leetcode id=3 lang=golang
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.50%)
 * Total Accepted:    968.1K
 * Total Submissions: 3.4M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
func lengthOfLongestSubstring(s string) int {
	max := 0
	left := 0
	m := make(map[byte]int)
	for k := 0; k < len(s); k++ {
		ch := s[k]
		p, ok := m[ch]
		if ok {
			for i := left;  i<= p; i++ {
				delete(m, s[i])
			}
			left = p + 1
		} else {
			count := k - left + 1
			if count > max {
				max = count
			}
		}
		m[ch] = k
	}

	return max
}
