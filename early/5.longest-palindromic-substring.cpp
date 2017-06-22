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
        string res;
        int m = s.size();
        if(m==0){
            return res;
        }
        
        int a[m][m];
        memset(a, 0, m*m*sizeof(int));
        for(int i=0;i<m;i++){
            a[i][i] = 1;
            
            if(res.size()<1){
                res = string(1, s[i]);
            }
            if(i+1<m&&s[i]==s[i+1]){
                a[i][i+1] = 2;
                
                if(res.size()<2){
                    res = string(2, s[i]);
                }
            }
        }
        
        for(int len=3;len<=m;len++){
            for(int i=0;i<m;i++){
                int j = i + len - 1;
                if(j<m && s[i]==s[j] && a[i+1][j-1]){
                    a[i][j] = a[i+1][j-1] + 2;
                    
                    if(res.size()<len){
                        res = s.substr(i, len);
                    }
                }
            }
        }
        
        return res;
    }
};
