/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (30.13%)
 * Likes:    9153
 * Dislikes: 557
 * Total Accepted:    1.5M
 * Total Submissions: 5.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int max_length = 0;
		int ch_of_index[256];
		for (auto& value : ch_of_index) {
			value = -1;
		}

		int start_pos = -1;
		for (int i=0; i< s.size(); i++) {
			int c = (int)s[i];
			int last_index = ch_of_index[c];
			if (last_index >= 0 && start_pos < last_index) {
				start_pos = last_index;
			}
			ch_of_index[c] = i;
			int len = i - start_pos;
			if (len > max_length) {
				max_length = len;
			}
		}

		return max_length;
    }
};
// @lc code=end
