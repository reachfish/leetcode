/*
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string
 *
 * Easy (33.46%)
 * Total Accepted:    30982
 * Total Submissions: 92598
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 * 
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s: "abab" p: "ab"
 * 
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size()<p.size()) { return res; }
        
        map<char, int> m1, m2;
        for(auto c : p) { m1[c]++; }
        
        int n = p.size();
        for(int i=0;i<n;i++){
            m2[s[i]]++;
        }
        
        if(m1==m2) { res.push_back(0); }
        for(int i=n;i<s.size();i++){
            m2[s[i]]++;
            m2[s[i-n]]--;
            if(m2[s[i-n]]==0) { m2.erase(s[i-n]); }
            if(m1==m2) { 
                res.push_back(i - n + 1); 
            }
        }
        
        return res;
    }
};
