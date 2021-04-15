/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (65.25%)
 * Likes:    2230
 * Dislikes: 132
 * Total Accepted:    188.7K
 * Total Submissions: 288.3K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an integer array nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that
 * appear only once. You can return the answer in any order.
 *
 * Follow up: Your algorithm should run in linear runtime complexity. Could you
 * implement it using only constant space complexity?
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,1,3,2,5]
 * Output: [3,5]
 * Explanation:  [5, 3] is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,0]
 * Output: [-1,0]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,1]
 * Output: [1,0]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each integer in nums will appear twice, only two integers will appear once.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int xors = 0;
    for (auto num : nums) {
      xors ^= num;
    }

    int i = 0;
    while (i < 31) {
      if (xors & (1 << i)) {
        break;
      }
      i++;
    }

    if (i == 32) {
      return {};
    }

    int a = 0, b = 0;
    int x = 1 << i;
    for (auto num : nums) {
      if (num & x) {
        a ^= num;
      } else {
        b ^= num;
      }
    }

    return {a, b};
  }
};
// @lc code=end
