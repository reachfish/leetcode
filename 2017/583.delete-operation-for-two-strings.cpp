/*
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings
 *
 * Medium (43.50%)
 * Total Accepted:    3851
 * Total Submissions: 8853
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 
 * Given two words word1 and word2, find the minimum number of steps required
 * to make word1 and word2 the same, where in each step you can delete one
 * character in either string.
 * 
 * 
 * Example 1:
 * 
 * Input: "sea", "eat"
 * Output: 2
 * Explanation: You need one step to make "sea" to "ea" and another step to
 * make "eat" to "ea".
 * 
 * 
 * 
 * Note:
 * 
 * The length of given words won't exceed 500.
 * Characters in given words can only be lower-case letters.
 * 
 * 
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size(); 
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++) { dp[i][0] = 0; }
        for(int j=0;j<=n;j++) { dp[0][j] = 0; }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int val = word1[i-1] == word2[j-1] ? dp[i-1][j-1] + 1 : 0;
                val = val > dp[i-1][j] ? val : dp[i-1][j];
                val = val > dp[i][j-1] ? val : dp[i][j-1];
                dp[i][j] = val;
            }
        }
        return m + n - 2 * dp[m][n];
    }
};
