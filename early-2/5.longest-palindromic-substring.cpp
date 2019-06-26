/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring
 *
 * Medium (25.12%)
 * Total Accepted:    203869
 * Total Submissions: 811489
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example:
 * 
 * Input: "babad"
 * 
 * Output: "bab"
 * 
 * Note: "aba" is also a valid answer.
 * 
 * 
 * 
 * Example:
 * 
 * Input: "cbbd"
 * 
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
		if(s.empty()) { return s; }

		int n = s.size();
		string res = s.substr(0, 1);

		bool dp[n][n];
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				dp[i][j] = i == j;
			}
		}

		for(int i = 0; i< n; i++){
			if(i<n-1 && s[i]==s[i+1]){
				dp[i][i+1] = true;
				res = s.substr(i, 2);
			}
		}

		for(int len = 3; len <= n ; len++){
			for(int i = 0; i<= n - len; i++){
				int j = i + len - 1;
				
				if(dp[i+1][j-1] && s[i] == s[j]){
					dp[i][j] = true;

					if(res.size() < len){
						res = s.substr(i, len);
					}
				}
			}
		}

		return res;
    }
};
