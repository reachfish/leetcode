/*
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement
 *
 * Medium (41.81%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"ABAB"\n2'
 *
 * Given a string that consists of only uppercase English letters, you can
 * replace any letter in the string with another letter at most k times. Find
 * the length of a longest substring containing all repeating letters you can
 * get after performing the above operations.
 * 
 * Note:
 * Both the string's length and k will not exceed 104.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * s = "ABAB", k = 2
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s = "AABABBA", k = 1
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 * 
 * 
 */
class Solution {
public:
    int characterReplacement(string s, int k) {
		int count[26];        
		memset(count, 0, sizeof(count));

		int maxCount = 0;
		int max = 0;

		int start = 0;
		for(int end=0;end<s.size();end++)
		{
			int idx = s[end] - 'A';
			count[idx]++;
			maxCount = maxCount > count[idx] ? maxCount : count[idx];

			while(end - start + 1 - maxCount > k)
			{
				bool chk = count[s[start] - 'A'] >= maxCount;
				count[s[start] - 'A']--;
				start++;

				if(chk){
					maxCount = 0;
					for(auto c : count) { maxCount = maxCount > c ? maxCount : c; }
				}
			}

			int len = end - start + 1;
			max = max > len ? max : len;
		}

		return max;
    }
};
