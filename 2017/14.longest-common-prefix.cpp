/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix
 *
 * Easy (31.34%)
 * Total Accepted:    175983
 * Total Submissions: 561593
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) { return ""; }
        string res = strs[0];
        
        for(auto s : strs){
            while(s.find(res)!=0) { res.pop_back(); }
            if(res.empty()) { break; }
        }
        
        return res;
    }
};
