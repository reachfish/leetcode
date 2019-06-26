/*
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram
 *
 * Easy (45.98%)
 * Total Accepted:    156195
 * Total Submissions: 339699
 * Testcase Example:  '""\n""'
 *
 * Given two strings s and t, write a function to determine if t is an anagram
 * of s. 
 * 
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        
        int len = s.size();
        if(len==0){
            return true;
        }
        
        int a[26];
        int b[26];
        memset(a, 0, 26*sizeof(int));
        memset(b, 0, 26*sizeof(int));
        
        for(int i=0;i<len;i++){
            a[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        
        return true;
    }
};
