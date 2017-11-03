/*
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii
 *
 * algorithms
 * Easy (31.89%)
 * Total Accepted:    11.1K
 * Total Submissions: 34.6K
 * Testcase Example:  '"aba"'
 *
 * 
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * 
 * Note:
 * 
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 * 
 * 
 */
class Solution {
public:
	bool isPalindrome(const string& s, int start, int end){
		while(start < end){
			if(s[start++] != s[end--]){
				return false;
			}
		}

		return true;
	}

    bool validPalindrome(string s) {
		int start = 0, end = s.size() - 1;        

		while(start < end){
			if(s[start++] != s[end--]){
				return isPalindrome(s, start - 1, end) || isPalindrome(s, start, end + 1);
			}
		}

		return true;
    }
};
