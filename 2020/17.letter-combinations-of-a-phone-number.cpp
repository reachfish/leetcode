/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (46.16%)
 * Likes:    3758
 * Dislikes: 405
 * Total Accepted:    596.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
		string dict[] = {
			"abc", "def",
			"ghi", "jkl", "mno",
			"pqrs", "tuv", "wxyz",
		};
		int cur = 0;
		std::vector<string> strs[2];
		int max_size = 4 * digits.size();
		strs[0].reserve(max_size);
		strs[1].reserve(max_size);
		const int kDictSize = sizeof(dict)/sizeof(dict[0]);
		for (auto c : digits) {
			int i = c - '2';
			if (i<0 || i>=kDictSize) {
				continue;
			}

			const auto& word = dict[i];
			auto& cur_strs = strs[cur];
			auto& last_strs = strs[1-cur];
			cur_strs.clear();
			if (!last_strs.empty()) {
				for (const auto& s : last_strs) {
					for (auto w : word) {
						cur_strs.push_back(s + std::string(1, w));
					}
				}
			} else {
				for (auto w : word) {
					cur_strs.push_back(std::string(1, w));
				}
			}

			cur = 1 - cur;
		}

		return strs[1 - cur];
    }
};
// @lc code=end
