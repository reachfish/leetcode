/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (24.44%)
 * Likes:    1885
 * Dislikes: 104
 * Total Accepted:    239.6K
 * Total Submissions: 980.4K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like ? or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
		std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>(p.size() + 1, 0));
		return iterate(dp, s.data(), s.data() + s.size(), p.data(), p.data() + p.size()); 
    }

	bool iterate(std::vector<std::vector<int>>& dp,
				 const char* s, const char* se, const char* p, const char* pe) {
		int i = se - s;
		int j = pe - p;
		auto& r = dp[i][j];
		if (r != 0) {
			return r > 0; 
		}

		if (s == se) {
			while (p != pe) {
				if (*p++ != '*') {
					r = -1;
					return false;
				}
			}
			r = 1;
			return true;
		}

		if (p == pe) {
			r = -1;
			return false;
		}

		if (*s == *p || *p == '?') {
			return iterate(dp, s+1, se, p+1, pe);
		}
		if (*p != '*') {
			r = -1;
			return false;
		}

		bool ok = iterate(dp, s + 1, se, p, pe) || iterate(dp, s, se, p + 1, pe) 
			    || iterate(dp, s + 1, se, p + 1, pe);
		r = ok ? 1 : -1;
		return ok;
	}
};
// @lc code=end
