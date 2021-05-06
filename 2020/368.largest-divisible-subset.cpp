/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 *
 * https://leetcode.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (38.49%)
 * Likes:    1851
 * Dislikes: 90
 * Total Accepted:    112K
 * Total Submissions: 290.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct positive integers nums, return the largest subset
 * answer such that every pair (answer[i], answer[j]) of elements in this
 * subset satisfies:
 *
 *
 * answer[i] % answer[j] == 0, or
 * answer[j] % answer[i] == 0
 *
 *
 * If there are multiple solutions, return any of them.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [1,2]
 * Explanation: [1,3] is also accepted.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,4,8]
 * Output: [1,2,4,8]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 2 * 10^9
 * All the integers in nums are unique.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }

    int max_count = 0;
    int max_i = -1;
    vector<int> dp(nums.size());
    sort(nums.begin(), nums.end());
    for (int i = 0; i < dp.size(); i++) {
      int max_prev = 0;
      for (int j = i - 1; j >= 0; j--) {
        if (dp[j] > max_prev && nums[i] % nums[j] == 0) {
          max_prev = dp[j];
        }
      }
      int count = max_prev + 1;
      dp[i] = count;
      if (count > max_count) {
        max_count = count;
        max_i = i;
      }
    }

    vector<int> result(max_count);
    int k = max_i;
    int last = nums[k];
    for (int i = max_count; i > 0; i--) {
      for (;; k--) {
        int v = nums[k];
        if (dp[k] == i && last % v == 0) {
          result[i - 1] = v;
          last = v;
          k--;
          break;
        }
      }
    }

    return result;
  }
};
// @lc code=end
