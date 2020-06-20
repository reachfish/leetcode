/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.52%)
 * Likes:    637
 * Dislikes: 2373
 * Total Accepted:    369.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word (last word means the last
 * appearing word if we loop from left to right) in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a maximal substring consisting of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int e = s.size() - 1;
        for (; e >= 0 && s[e] == ' '; --e) {
        }
        int b = e;
        for (; b >= 0 && s[b] != ' '; --b) {
        }

        if (e >= 0) {
            return e - b;
        } else {
            return 0;
        }
    }
};
// @lc code=end
