/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 *
 * https://leetcode.com/problems/count-of-range-sum/description/
 *
 * algorithms
 * Hard (35.95%)
 * Likes:    1028
 * Dislikes: 119
 * Total Accepted:    50K
 * Total Submissions: 137.5K
 * Testcase Example:  '[-2,5,-1]\n-2\n2'
 *
 * Given an integer array nums and two integers lower and upper, return the
 * number of range sums that lie in [lower, upper] inclusive.
 *
 * Range sum S(i, j) is defined as the sum of the elements in nums between
 * indices i and j inclusive, where i <= j.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-2,5,-1], lower = -2, upper = 2
 * Output: 3
 * Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their
 * respective sums are: -2, -1, 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0], lower = 0, upper = 0
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * -3 * 10^4 <= lower <= upper <= 3 * 10^4
 *
 *
 *
 * Follow up: A naive algorithm of O(n^2) is trivial, Could you do better than
 * that?
 */

// @lc code=start
class Solution {
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    int max_sum = 0;
    int max_start = -1;
    int min_sum = 0;
    int min_start = -1;

    for (int i = 0; i < nums.size(); i++) {
    }
  }
};
// @lc code=end
