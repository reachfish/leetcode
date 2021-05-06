/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (61.29%)
 * Likes:    7111
 * Dislikes: 545
 * Total Accepted:    741.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 *
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 *
 *
 * Follow up:
 *
 *
 * Could you solve it in O(n) time complexity and without using division?
 * Could you solve it with O(1) constant space complexity? (The output array
 * does not count as extra space for space complexity analysis.)
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    int product = 1;
    for (int i = 0; i < nums.size() - 1; i++) {
      product *= nums[i];
      result[i + 1] = product;
    }

    product = 1;
    for (int i = nums.size() - 1; i > 0; i--) {
      product *= nums[i];
      result[i - 1] *= product;
    }

    return result;
  }
};
// @lc code=end
