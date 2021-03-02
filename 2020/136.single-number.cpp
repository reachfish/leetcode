/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (66.41%)
 * Likes:    5792
 * Dislikes: 189
 * Total Accepted:    1.1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers nums, every element appears twice except
 * for one. Find that single one.
 *
 * Follow up: Could you implement a solution with a linear runtime complexity
 * and without using extra memory?
 *
 *
 * Example 1:
 * Input: nums = [2,2,1]
 * Output: 1
 * Example 2:
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 * Example 3:
 * Input: nums = [1]
 * Output: 1
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * Each element in the array appears twice except for one element which appears
 * only once.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int num = 0;
    for (auto n : nums) {
      num ^= n;
    }

    return num;
  }
};
// @lc code=end
