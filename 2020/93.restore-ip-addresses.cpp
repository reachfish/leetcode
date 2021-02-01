/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (37.33%)
 * Likes:    1611
 * Dislikes: 545
 * Total Accepted:    223.5K
 * Total Submissions: 598.2K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string s containing only digits, return all possible valid IP
 * addresses that can be obtained from s. You can return them in any order.
 * 
 * A valid IP address consists of exactly four integers, each integer is
 * between 0 and 255, separated by single dots and cannot have leading zeros.
 * For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and
 * "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP
 * addresses. 
 * 
 * 
 * Example 1:
 * Input: s = "25525511135"
 * Output: ["255.255.11.135","255.255.111.35"]
 * Example 2:
 * Input: s = "0000"
 * Output: ["0.0.0.0"]
 * Example 3:
 * Input: s = "1111"
 * Output: ["1.1.1.1"]
 * Example 4:
 * Input: s = "010010"
 * Output: ["0.10.0.10","0.100.1.0"]
 * Example 5:
 * Input: s = "101023"
 * Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 3000
 * s consists of digits only.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        dp(result, ip, s, 0, 0);
        return result;
    }

    void dp(vector<string>& result, string& ip, const std::string& s, int index, int parts) {
        if (parts > 4) { return; }

        if (index == s.size()) {
            if (parts == 4) { result.push_back(ip); }
            return;
        }

        if (parts != 0) { ip.push_back('.'); }

        size_t sz = ip.size();
        ip.push_back(s[index]);
        dp(result, ip, s, index + 1, parts + 1);

        if (s[index] != '0') {
            if (index + 1 < s.size()) {
                ip.resize(sz);
                ip.push_back(s[index]);
                ip.push_back(s[index + 1]);
                dp(result, ip, s, index + 2, parts + 1);
            }

            if (index + 2 < s.size() &&
                (s[index] - '0') * 100 + (s[index + 1] - '0') * 10 + (s[index + 2] - '0') <= 255) {
                ip.resize(sz);
                ip.push_back(s[index]);
                ip.push_back(s[index + 1]);
                ip.push_back(s[index + 2]);
                dp(result, ip, s, index + 3, parts + 1);
            }
        }
    }
};
// @lc code=end
