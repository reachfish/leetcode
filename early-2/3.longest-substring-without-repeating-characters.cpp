/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters
 *
 * Medium (24.15%)
 * Total Accepted:    297780
 * Total Submissions: 1232827
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		map<char, int> m;

		int cur = 0;
		int max = 0;
		for(int i=0;i<s.size();i++){
			char c = s[i];
			int pre = m.count(c) ? m[c] : -1;
			int len = i - pre;
			cur++;
			if(cur > len){
				cur = len;
			}

			if(cur > max){
				max = cur;
			}

			m[c] = i;
		}

		return max;
    }
};
