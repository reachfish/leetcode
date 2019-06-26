/*
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii
 *
 * Easy (43.90%)
 * Total Accepted:    15173
 * Total Submissions: 34564
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 * 
 * 
 * Example:
 * 
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * 
 * 
 * 
 * Restrictions: 
 * 
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 * 
 */
class Solution {
public:
    string reverseStr(string s, int k) {
        if(k<=1) { return s; }
        for(int i=0;i<s.size();i+= 2 * k){
            //first k
            int j1 = i + k - 1;
            int j2 = s.size() - 1;
            int j = j1 < j2 ? j1 : j2;
            int h = i;
            while(h<j) { swap(s[h++], s[j--]); }
        }
        
        return s;
    }
};
