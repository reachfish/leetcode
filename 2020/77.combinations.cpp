/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (55.92%)
 * Likes:    1785
 * Dislikes: 74
 * Total Accepted:    318.3K
 * Total Submissions: 569.1K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, k = 1
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
 * 1 <= k <= n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0 || n < k) {
            return {};
        }

        vector<int> sample(k);
        vector<vector<int>> result;

        helper(result, sample, n, 1, k, 0);
        return result;
    }

    void helper(vector<vector<int>>& result, vector<int>& sample, int n, int i, int k, int j) {
        if (j == k) {
            result.push_back(sample);
            return;
        }
        if ((n - i + 1) < (k - j)) {
            return;
        }
        sample[j] = i;
        helper(result, sample, n, i + 1, k, j + 1);
        helper(result, sample, n, i + 1, k, j);
    }
};
// @lc code=end
