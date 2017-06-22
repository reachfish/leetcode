/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr
 *
 * Easy (27.78%)
 * Total Accepted:    182243
 * Total Submissions: 656028
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
        if(haystack.size() < needle.size()) return -1;
        
        int nsize = needle.size();
        if(nsize==0) return 0;
        
        for(int i=0;i<haystack.size()-nsize + 1;i++){
            if(haystack.substr(i, nsize)==needle)
                return i;
        }
        
        return -1;
    }
};
