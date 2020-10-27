/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (43.76%)
 * Likes:    1705
 * Dislikes: 268
 * Total Accepted:    442.1K
 * Total Submissions: 1M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 * 
 * Constraints:
 * 
 * 
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int v = 0;
        string s;
        int i = a.size() - 1;
        int j = b.size() - 1;

        auto add_tail_value = [&](int delta) {
            v += delta;
            if (v > 1) {
                v -= 2;
                s.push_back((char)(v + '0'));
                v = 1;
            } else {
                s.push_back((char)(v + '0'));
                v = 0;
            }
        };

        for (; i >= 0 && j >= 0; i--, j--) {
            add_tail_value(a[i] + b[j] - 2 * '0');
        }

        int k         = i >= j ? i : j;
        const auto& d = i >= j ? a : b;
        for (; k >= 0; k--) {
            add_tail_value(d[k] - '0');
        }
        if (v > 0) {
            s.push_back('1');
        }

        std::reverse(s.begin(), s.end());

        return s;
    }
};
// @lc code=end
