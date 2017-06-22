/*
 * [474] Ones and Zeroes
 *
 * https://leetcode.com/problems/ones-and-zeroes
 *
 * Medium (38.10%)
 * Total Accepted:    10273
 * Total Submissions: 26973
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * In the computer world, use restricted resource you have to generate maximum
 * benefit is what we always want to pursue.
 * For now, suppose you are a dominator of m 0s and n 1s respectively. On the
 * other hand, there is an array with strings consisting of only 0s and 1s.
 * 
 * 
 * Now your task is to find the maximum number of strings that you can form
 * with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 * 
 * 
 * 
 * Note:
 * 
 * The given numbers of 0s and 1s will both not exceed 100
 * The size of given string array won't exceed 600.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * Output: 4
 * 
 * Explanation: This are totally 4 strings can be formed by the using of 5 0s
 * and 3 1s, which are “10,”0001”,”1”,”0”
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: Array = {"10", "0", "1"}, m = 1, n = 1
 * Output: 2
 * 
 * Explanation: You could form "10", but then you'd have nothing left. Better
 * form "0" and "1".
 * 
 * 
 */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(m<0 || n<0 || m+n == 0) { return 0; }
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(auto s : strs){
            int one = 0;
            int zero = 0;
            for(auto c : s) { if(c=='0'){zero++;} else{one++;} }
            vector<vector<int>> tmp = dp;
            for(int i=zero;i<=m;i++){
                for(int j=one;j<=n;j++){
                    tmp[i][j] = dp[i][j] > dp[i-zero][j-one] + 1 ? dp[i][j] : dp[i-zero][j-one] + 1; 
                }
            }
            dp = tmp;
        }
        
        return dp[m][n];
    }
};
