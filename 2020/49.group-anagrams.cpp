/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (56.00%)
 * Likes:    3416
 * Dislikes: 180
 * Total Accepted:    670.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> m;
		for (const auto& s : strs) {
			auto k = s;
			sort(k.begin(), k.end());
			m[k].push_back(s);
		}
		vector<vector<string>> result;
		result.reserve(m.size());
		for (const auto& v : m) {
			result.push_back(v.second);
		}

		return result;
    }
};
// @lc code=end
