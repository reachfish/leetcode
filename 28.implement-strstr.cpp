/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr
 *
 * algorithms
 * Easy (28.05%)
 * Total Accepted:    198.5K
 * Total Submissions: 706.1K
 * Testcase Example:  '""\n""'
 *
 * 
 * Implement strStr().
 * 
 * 
 * Returns the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
		if(needle.empty()) {
			return 0;
		}

		for(int i=0; i<=(int)(haystack.size() - needle.size()); i++){
			if(haystack.substr(i, needle.size()) == needle){
				return i;
			}
		}

		return -1;
    }
};
