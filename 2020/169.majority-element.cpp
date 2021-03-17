/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (59.91%)
 * Likes:    4717
 * Dislikes: 254
 * Total Accepted:    805.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array nums of size n, return the majority element.
 *
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 *
 *
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: 3
 * Example 2:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 * Follow-up: Could you solve the problem in linear time and in O(1) space?
 */

// @lc code=start
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    int count = 0;
    int major = nums[0];
    for (auto n : nums) {
      if (n == major) {
        count++;
      } else if (--count == 0) {
        major = n;
        count = 1;
      }
    }

    return major;
  }
};
// @lc code=end
