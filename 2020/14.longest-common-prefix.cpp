/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.19%)
 * Likes:    2458
 * Dislikes: 1827
 * Total Accepted:    737K
 * Total Submissions: 2.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) {
			return "";
		}

		int end = -1;
		bool ok = true;
		for(int i=0;ok;i++) {
			for (const auto& str : strs) {
				if (str.size() <= i || str[i] != strs[0][i]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				end = i;
			}
		}

		return end >= 0 ? strs[0].substr(0, end + 1) : "";
    }
};
// @lc code=end
