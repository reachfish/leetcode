/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (53.62%)
 * Likes:    2396
 * Dislikes: 397
 * Total Accepted:    277.6K
 * Total Submissions: 515.6K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given an integer array nums where every element appears three times except
 * for one, which appears exactly once. Find the single element and return
 * it.
 *
 *
 * Example 1:
 * Input: nums = [2,2,3,2]
 * Output: 3
 * Example 2:
 * Input: nums = [0,1,0,1,0,1,99]
 * Output: 99
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each element in nums appears exactly three times except for one element
 * which appears once.
 *
 *
 *
 * Follow up: Your algorithm should have a linear runtime complexity. Could you
 * implement it without using extra memory?
 *
 */

// @lc code=start
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    std::vector<int> part(32, 0);
    for (auto n : nums) {
      for (int i = 0; i < part.size(); i++) {
        part[i] += (n >> i) & 1;
      }
    }

    int res = 0;
    for (int i = 0; i < part.size(); i++) {
      res |= (part[i] % 3) << i;
    }

    return res;
  }
};
// @lc code=end
