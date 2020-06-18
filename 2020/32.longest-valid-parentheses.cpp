/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (28.00%)
 * Likes:    3335
 * Dislikes: 133
 * Total Accepted:    278.5K
 * Total Submissions: 994.7K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n <= 1) {
            return 0;
        }

        int max = 0;
        int dp[n];
        dp[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            dp[i] = 0;
            if (s[i] != ')') {
                continue;
            }

            int len = 0;
            if (s[i - 1] == '(') {
                len = getLen(dp, i - 2) + 2;
            } else if (s[i - 1] == ')') {
                int count = dp[i - 1];
                if (count > 0) {
                    int j = i - count - 1;
                    if (j >= 0 && s[j] == '(') {
                        len = dp[i - 1] + 2 + getLen(dp, j - 1);
                    }
                }
            }

            dp[i] = len;
            if (len > max) {
                max = len;
            }
        }

        return max;
    }

    inline int getLen(int dp[], int i) { return i >= 0 ? dp[i] : 0; }
};
// @lc code=end
