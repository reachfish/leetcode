/*
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning
 *
 * Medium (32.48%)
 * Total Accepted:    94569
 * Total Submissions: 291129
 * Testcase Example:  '"aab"'
 *
 * 
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * 
 * For example, given s = "aab",
 * 
 * Return
 * 
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */
class Solution {
public:
    
    bool isPalin(const string& s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        
        return true;
    }
    
    void helper(const string& s, const vector<vector<bool>>& palin, int i, vector<vector<string> >&res, vector<string>& p){
        if(i>=s.size()){
            res.push_back(p);
            return;
        }
        
        int len = p.size();
        for(int j=i;j<s.size();j++){
            if(palin[i][j]){
                p.push_back(s.substr(i, j-i+1));
                helper(s, palin, j+1, res, p);
                p.erase(p.begin()+len, p.end());
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        
        if(s.empty()){
            return res;    
        }
        
        int len = s.size();
        vector<vector<bool>> palin(len, vector<bool>(len));
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                palin[i][j] = isPalin(s, i, j);
            }
        }
        
        vector<string> p;
        helper(s, palin, 0, res, p);
        
        return res;
    }
};
