/*
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string
 *
 * Medium (36.47%)
 * Total Accepted:    5736
 * Total Submissions: 15726
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 * 
 * Example 1:
 * 
 * Input:s1 = "ab" s2 = "eidbaooo"
 * Output:True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 * 
 * 
 * 
 * Note:
 * 
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 * 
 * 
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size() || s2.empty()) { return false; }
        
        map<char, int> m1, m2;
        for(auto c : s1) { m1[c]++; }
        
        int n = s1.size();
        for(int i=0;i<n;i++) { m2[s2[i]]++; }
        
        if(m1==m2) { return true; }
        for(int i=n;i<s2.size();i++){
            m2[s2[i]]++;
            m2[s2[i-n]]--;
            if(m2[s2[i-n]]==0) { m2.erase(s2[i-n]); }
            if(m1==m2) { return true; }
        }
        
        return false;
    }
};
