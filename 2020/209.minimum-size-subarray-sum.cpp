/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (39.26%)
 * Likes:    3551
 * Dislikes: 137
 * Total Accepted:    345.1K
 * Total Submissions: 869.1K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of positive integers nums and a positive integer target,
 * return the minimal length of a contiguous subarray [numsl, numsl+1, ...,
 * numsr-1, numsr] of which the sum is greater than or equal to target. If
 * there is no such subarray, return 0 instead.
 *
 *
 * Example 1:
 *
 *
 * Input: target = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem
 * constraint.
 *
 *
 * Example 2:
 *
 *
 * Input: target = 4, nums = [1,4,4]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution of which the time complexity is O(n log(n)).
 */

// @lc code=start
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int start = 0;
    int min_len = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (sum < target) {
        continue;
      }

      while (start < i) {
        int s = sum - nums[start];
        if (s < target) {
          break;
        }
        sum = s;
        ++start;
      }

      int len = i - start + 1;
      if (len < min_len || min_len == 0) {
        min_len = len;
        if (len == 1) {
          break;
        }
      }
    }

    return min_len;
  }
};
// @lc code=end
