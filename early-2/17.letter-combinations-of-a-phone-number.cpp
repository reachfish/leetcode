/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number
 *
 * algorithms
 * Medium (34.39%)
 * Total Accepted:    162.3K
 * Total Submissions: 471.1K
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
		string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		vector<string> res;        
		res.push_back("");

		for(auto c : digits){
			if(!isdigit(c)||dict[c-'0'].empty()){
				continue;
			}

			string d = dict[c-'0'];
			size_t size = res.size();
			for(int j=0;j<size; j++){
				string tmp = res[j];
				for(int i=1;i<d.size();i++){
					res.push_back(tmp + string(1, d[i]));
				}

				res[j].push_back(d[0]);
			}
		}

		if(res.size()==1){
			res.clear();
		}

		return res;
    }
};
