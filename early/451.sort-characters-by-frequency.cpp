/*
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency
 *
 * Medium (50.74%)
 * Total Accepted:    28330
 * Total Submissions: 55836
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 * 
 * Example 1:
 * 
 * Input:
 * "tree"
 * 
 * Output:
 * "eert"
 * 
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * "cccaaa"
 * 
 * Output:
 * "cccaaa"
 * 
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * "Aabb"
 * 
 * Output:
 * "bbAa"
 * 
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 * 
 * 
 */
class Solution {
public:
    static bool compare(const pair<char, int>& a, const pair<char, int>& b){
        return a.second > b.second;    
    }
    
    string frequencySort(string s) {
        map<char, int> m;
        for(auto c : s){
            m[c]++;
        }
        
        vector<pair<char, int> > v;
        for(auto it : m){
            v.push_back(make_pair(it.first, it.second));
        }
        
        sort(v.begin(), v.end(), Solution::compare);
        string res;
        for(auto e : v){
            res += string(e.second, e.first);
        }
        
        return res;
    }
};
