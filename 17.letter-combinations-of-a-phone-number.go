/*
 * @lc app=leetcode id=17 lang=golang
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (41.90%)
 * Total Accepted:    402.5K
 * Total Submissions: 960.3K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

var dict = []string {
	"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
}

func letterCombinations(digits string) []string {
	n := len(digits)
	if n == 0 {
		return []string{}
	}

	result := make([]string, 0)
	letters := make([]rune, n)
	result = iterate(result, digits, letters, 0)

	return result
}

func iterate(result []string, digits string, letters []rune, idx int) []string {
	if idx == len(digits) {
		result = append(result, string(letters[:]))
	} else {
		for _, ch := range(dict[digits[idx] - '2']) {
			letters[idx] = ch
			result = iterate(result, digits, letters, idx + 1)
		}
	}

	return result
}
