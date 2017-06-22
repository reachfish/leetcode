/*
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note
 *
 * Easy (46.86%)
 * Total Accepted:    52775
 * Total Submissions: 112626
 * Testcase Example:  '"a"\n"b"'
 *
 * 
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom 
 * note can be constructed from the magazines ; otherwise, it will return
 * false. 
 * 
 * 
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 * 
 * 
 * Note:
 * You may assume that both strings contain only lowercase letters.
 * 
 * 
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * 
 * 
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m1, m2;
        for(auto c : ransomNote) { m1[c]++; }
        for(auto c : magazine) { m2[c]++; }
        for(auto p : m1) { if(p.second > m2[p.first])  return false; }
        
        return true;
    }
};
