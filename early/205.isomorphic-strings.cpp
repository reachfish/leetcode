/*
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings
 *
 * Easy (33.44%)
 * Total Accepted:    103777
 * Total Submissions: 310380
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * For example,
 * Given "egg", "add", return true.
 * 
 * Given "foo", "bar", return false.
 * 
 * Given "paper", "title", return true.
 * 
 * Note:
 * You may assume both s and t have the same length.
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m1, m2;
        if(s.size()!=t.size()){
            return false;
        }
        
        for(int i=0;i<s.size();i++){
            char a = s[i];
            char b = t[i];
            
            //a -> b
            if(m1.count(a)){
                if(m1[a]!=b) return false;
            }
            else{
                if(m2.count(b)) return false;
                m1[a] = b;
                m2[b] = a;
            }
        }
        
        return true;
    }
};
