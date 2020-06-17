/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.24%)
 * Likes:    6680
 * Dislikes: 527
 * Total Accepted:    922.7K
 * Total Submissions: 3.2M
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

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
		if (s.empty()) {
			return s;
		}

		int max_length = 0;
		int max_start = 0;

		int n = s.size();
		bool dp[n][n];
		for (int i=0; i<n; i++) {
			for (int j=i; j<n; j++) {
				if ((i==j) || (j==i+1 && s[i]==s[j])) {
					dp[i][j] = true;
					int length = j - i + 1;
					if (length > max_length) {
						max_length = length;
						max_start = i;
					}
				} else {
					dp[i][j] = false;
				}
			}
		}

		bool odd_ok = max_length >= 1;
		bool even_ok = max_length >= 2;
		for (int length=3; length<=s.size(); length++) {
			bool is_odd = length & 1;
			if (is_odd) {
				if (!odd_ok) { continue; }
			} else {
				if (!even_ok) { continue; }
			}

			for (int i=0; i<=int(s.size() - length); i++) {
				int j = i + length - 1;
				if (s[i] == s[j] && dp[i+1][j-1]) {
					dp[i][j] = true;
					if (max_length != length) {
						max_length = length;
						max_start = i;
					}
				}
			}

			if (length != max_length) {
				if (is_odd){
					odd_ok = false;
				} else {
					even_ok = false;
				}

				if (!odd_ok && !even_ok) {
					break;
				}
			}
		}

		return s.substr(max_start, max_length);
    }
};
// @lc code=end
