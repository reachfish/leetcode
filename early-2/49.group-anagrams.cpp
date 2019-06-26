/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams
 *
 * Medium (33.72%)
 * Total Accepted:    133200
 * Total Submissions: 394971
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * 
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * 
 * [
 * ⁠ ["ate", "eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note: All inputs will be in lower-case.
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>, vector<string> > M;
        for(auto str : strs){
            map<char, int> m;
            for(auto c : str) { m[c]++; }
            M[m].push_back(str);
        }        

        vector<vector<string>> res;
        for(auto it : M){
            res.push_back(it.second);
        }

        return res;
    }
};
