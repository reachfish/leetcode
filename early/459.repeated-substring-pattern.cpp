/*
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern
 *
 * Easy (38.30%)
 * Total Accepted:    29747
 * Total Submissions: 77680
 * Testcase Example:  '"abab"'
 *
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together.
 * You may assume the given string consists of lowercase English letters only
 * and its length  will not exceed 10000. 
 * 
 * Example 1:
 * 
 * Input: "abab"
 * 
 * Output: True
 * 
 * Explanation: It's the substring "ab" twice.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aba"
 * 
 * Output: False
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: "abcabcabcabc"
 * 
 * Output: True
 * 
 * Explanation: It's the substring "abc" four times. (And the substring
 * "abcabc" twice.)
 * 
 * 
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        for(int i=len/2;i>=1;i--){
            if(len%i){
                continue;
            }
            
            string p = s.substr(0, i);
            int j=i;
            while(j<len){
                if(s.substr(j, i)!=p){
                    break;
                }
                
                j += i;
            }
            
            if(j==len){
                return true;
            }
        }
        
        return false;
    }
};
