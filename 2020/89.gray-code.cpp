/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (50.18%)
 * Likes:    763
 * Dislikes: 1712
 * Total Accepted:    174.4K
 * Total Submissions: 347.6K
 * Testcase Example:  '2'
 *
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 * 
 * Given an integer n representing the total number of bits in the code, return
 * any sequence of gray code.
 * 
 * A gray code sequence must begin with 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: [0,1,3,2]
 * Explanation:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * [0,2,3,1] is also a valid gray code sequence.
 * 00 - 0
 * 10 - 2
 * 11 - 3
 * 01 - 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 16
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n <= 0) { return {}; }

        int count = 1;
        for (int i = 0; i < n; i++) { count <<= 1; }

        vector<int> codes(count);
        vector<bool> exists(count, false);

        int v     = 0;
        codes[0]  = v;
        exists[v] = true;

        for (int i = 1; i < count; i++) {
            for (int k = 0; k < n; k++) {
                int x = v ^ (1 << k);
                if (!exists[x]) {
                    exists[x] = true;
                    codes[i]  = x;
                    v         = x;
                    break;
                }
            }
        }

        return codes;
    }
};
// @lc code=end
