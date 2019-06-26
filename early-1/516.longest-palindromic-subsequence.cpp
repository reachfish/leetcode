/*
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence
 *
 * Medium (42.55%)
 * Total Accepted:    11068
 * Total Submissions: 26012
 * Testcase Example:  '"bbbab"'
 *
 * 
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 * 
 * 
 * Example 1:
 * Input: 
 * 
 * "bbbab"
 * 
 * Output: 
 * 
 * 4
 * 
 * One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * Example 2:
 * Input:
 * 
 * "cbbd"
 * 
 * Output:
 * 
 * 2
 * 
 * One possible longest palindromic subsequence is "bb".
 * 
 */
class Solution {
public:
    int Max(int a, int b){
        return a > b ? a : b;
    }
    int longestPalindromeSubseq(string s) {
        int max = 0;
        int m = s.size();
        if(m==0){
            return 0;
        }
        
        int a[m][m] = {0};
        memset(a, 0, m*m*sizeof(int));
        for(int i=0;i<s.size();i++){
            a[i][i] = 1;
            max = Max(max, 1);
            if(i+1<s.size()){
                a[i][i+1] = s[i]==s[i+1] ? 2 : 1;
                max = Max(max, a[i][i+1]);
            }
        }
        
        for(int len = 3;len<=m;len++){
            for(int i=0;i<m;i++){
                int j = i + len - 1;
                if(j<m){
                    a[i][j] = Max(s[i]==s[j] ? a[i+1][j-1] + 2 : a[i+1][j-1], Max(a[i][j-1], a[i+1][j]));
                    max = Max(a[i][j], max);
                }
            }
        }
        
        return max;
    }
};
