/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number
 *
 * Medium (33.94%)
 * Total Accepted:    149222
 * Total Submissions: 439654
 * Testcase Example:  '""'
 *
 * Given a digit string, return all possible letter combinations that the
 * number could represent.
 * 
 * 
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below.
 * 
 * 
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        vector<string> res;
        res.push_back("");
        
        string s;
        for(int i=0;i<digits.size();i++){
            string pattern = m[digits[i]];
            if(pattern.empty()){
                continue;
            }
            
            size_t len = res.size();
            for(int j=0;j<pattern.size();j++){
                for(int k=0;k<len;k++){
                    res.push_back(res[k]+pattern[j]);
                }
            }
            
            res.erase(res.begin(), res.begin()+len);
        }
        
        if(res[0].empty()){
            res.clear();
        }
        
        return res;
    }
};
