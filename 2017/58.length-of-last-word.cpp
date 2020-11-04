/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word
 *
 * Easy (31.67%)
 * Total Accepted:    143870
 * Total Submissions: 454239
 * Testcase Example:  '""'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * 
 * For example, 
 * Given s = "Hello World",
 * return 5.
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = 0;
        int end = -1;
        for(int i=s.size()-1;i>=0;i--){
            if(end < 0){  
                if(s[i]!=' ') { end = i; } 
            }
            else {
                if(s[i]==' ') { start = i + 1; break; }
            }
        }
        
        return end < 0 ? 0 : end - start + 1;
    }
};
