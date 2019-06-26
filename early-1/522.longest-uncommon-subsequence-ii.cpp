/*
 * [522] Longest Uncommon Subsequence II
 *
 * https://leetcode.com/problems/longest-uncommon-subsequence-ii
 *
 * Medium (30.13%)
 * Total Accepted:    4032
 * Total Submissions: 13379
 * Testcase Example:  '["aba","cdc","eae"]'
 *
 * 
 * Given a list of strings, you need to find the longest uncommon subsequence
 * among them. The longest uncommon subsequence is defined as the longest
 * subsequence of one of these strings and this subsequence should not be any
 * subsequence of the other strings.
 * 
 * 
 * 
 * A subsequence is a sequence that can be derived from one sequence by
 * deleting some characters without changing the order of the remaining
 * elements. Trivially, any string is a subsequence of itself and an empty
 * string is a subsequence of any string.
 * 
 * 
 * 
 * The input will be a list of strings, and the output needs to be the length
 * of the longest uncommon subsequence. If the longest uncommon subsequence
 * doesn't exist, return -1.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba", "cdc", "eae"
 * Output: 3
 * 
 * 
 * 
 * Note:
 * 
 * All the given strings' lengths will not exceed 10.
 * The length of the given list will be in the range of [2, 50].
 * 
 * 
 */
class Solution {
public:
    int max(int a, int b){
        return a > b ? a : b;
    }
    
    bool isSubStr(const string& s1, const string& s2){
        if(s1.empty()||s2.empty()){
            return true;
        }
        
        int m = s1.size();
        int n = s2.size();
        if(m>n){
            return false;
        }
        
        int a[m+1][n+1];
        for(int i=0;i<=m;i++){
            a[i][0] = 0;
        }
        for(int j=0;j<=n;j++){
            a[0][j] = 0;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                a[i][j] = max(a[i-1][j-1] + (s1[i-1]==s2[j-1] ? 1:0), max(a[i-1][j], a[i][j-1]));
            }
        }
        
        return a[m][n] == m;
    }
    
    int findLUSlength(vector<string>& strs) {
        int res = -1;
        for(int i=0;i<strs.size();i++){
            bool sub = false;
            for(int j=0;j<strs.size();j++){
                if(i==j){
                    continue;    
                }
                
                if(isSubStr(strs[i], strs[j])){
                    sub = true;
                    break;
                }
            }
            
            if(!sub){
                int len = strs[i].size();
                res = res > len ?  res : len;
            }
        }
        
        return res;
    }
};
