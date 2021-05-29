/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (60.80%)
 * Likes:    1874
 * Dislikes: 67
 * Total Accepted:    230.5K
 * Total Submissions: 377.3K
 * Testcase Example:  '3\n7'
 *
 * Find all valid combinations of k numbers that sum up to n such that the
 * following conditions are true:
 *
 *
 * Only numbers 1 through 9 are used.
 * Each number is used at most once.
 *
 *
 * Return a list of all possible valid combinations. The list must not contain
 * the same combination twice, and the combinations may be returned in any
 * order.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * Explanation:
 * 1 + 2 + 4 = 7
 * There are no other valid combinations.
 *
 * Example 2:
 *
 *
 * Input: k = 3, n = 9
 * Output: [[1,2,6],[1,3,5],[2,3,4]]
 * Explanation:
 * 1 + 2 + 6 = 9
 * 1 + 3 + 5 = 9
 * 2 + 3 + 4 = 9
 * There are no other valid combinations.
 *
 *
 * Example 3:
 *
 *
 * Input: k = 4, n = 1
 * Output: []
 * Explanation: There are no valid combinations. [1,2,1] is not valid because 1
 * is used twice.
 *
 *
 * Example 4:
 *
 *
 * Input: k = 3, n = 2
 * Output: []
 * Explanation: There are no valid combinations.
 *
 *
 * Example 5:
 *
 *
 * Input: k = 9, n = 45
 * Output: [[1,2,3,4,5,6,7,8,9]]
 * Explanation:
 * 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
 * ​​​​​​​There are no other valid combinations.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= k <= 9
 * 1 <= n <= 60
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> nums;
    nums.reserve(k);

    dp(1, k, n, nums, result);

    return result;
  }

  void dp(int start, int k, int left, vector<int>& nums,
          vector<vector<int>>& result) {
    if (left == 0) {
      if (nums.size() == k) {
        result.push_back(nums);
      }
      return;
    }

    if (nums.size() == k) {
      return;
    }

    for (int i = start; i <= 9; i++) {
      if (i > left) {
        break;
      }

      nums.push_back(i);
      dp(i + 1, k, left - i, nums, result);
      nums.pop_back();
    }
  }
};
// @lc code=end
