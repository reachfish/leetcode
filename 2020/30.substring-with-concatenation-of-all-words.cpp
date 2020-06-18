/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (25.15%)
 * Likes:    829
 * Dislikes: 1215
 * Total Accepted:    173.7K
 * Total Submissions: 690.4K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) {
            return {};
        }

        vector<int> result;
        map<string, int> word_count;
        for (const auto& w : words) {
            word_count[w]++;
        }

        int n   = words.size();
        int len = words[0].size();
        std::map<string, int> tmp_count;
        for (int i = 0; i <= (int)(s.size() - n * len); i++) {
            int j = -1;
            tmp_count.clear();
            for (j = 0; j < n; j++) {
                std::string w = s.substr(i + j * len, len);
                auto it       = word_count.find(w);
                auto w_count  = it != word_count.end() ? it->second : 0;
                if (w_count == 0 || tmp_count[w] >= w_count) {
                    break;
                }
                ++tmp_count[w];
            }
            if (j == n) {
                result.push_back(i);
            }
        }

        return result;
    }
};
// @lc code=end
