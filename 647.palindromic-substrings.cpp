/*
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings
 *
 * algorithms
 * Medium (56.75%)
 * Total Accepted:    4.4K
 * Total Submissions: 7.8K
 * Testcase Example:  '"abc"'
 *
 * 
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * 
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters. 
 * 
 * 
 * Example 1:
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * Note:
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 */
class Solution {
public:
    int countSubstrings(string s) {
		if(s.empty()) { return 0; }        
		int n = s.size();
		bool dp[n][n];
		int res = 0;
		for(int i=0; i<n; i++){
			dp[i][i] = true;
			res++;
			if(i<n-1){
				dp[i][i+1] = s[i]==s[i+1];
				if(dp[i][i+1]){
					res++;
				}
			}
			for(int j=i+2; j<n; j++){
				dp[i][j] = false;
			}
		}

		for(int len=3;len<=n;len++){
			for(int i=0; i<=n-len; i++){
				int j = i + len - 1; 
				if(s[i]==s[j]&&dp[i+1][j-1]){
					dp[i][j] = true;
					res++;
				}
			}
		}

		return res;
    }
};
