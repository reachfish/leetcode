/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (56.26%)
 * Likes:    4455
 * Dislikes: 308
 * Total Accepted:    396.4K
 * Total Submissions: 700.3K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array nums of n integers where nums[i] is in the range [1, n],
 * return an array of all the integers in the range [1, n] that do not appear
 * in nums.
 *
 *
 * Example 1:
 * Input: nums = [4,3,2,7,8,2,3,1]
 * Output: [5,6]
 * Example 2:
 * Input: nums = [1,1]
 * Output: [2]
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 10^5
 * 1 <= nums[i] <= n
 *
 *
 *
 * Follow up: Could you do it without extra space and in O(n) runtime? You may
 * assume the returned list does not count as extra space.
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (auto n : nums) {
      int i = abs(n) - 1;
      if (nums[i] > 0) {
        nums[i] = -nums[i];
      }
    }

    vector<int> result;
    for (int i = 1; i <= nums.size(); i++) {
      if (nums[i - 1] > 0) {
        result.push_back(i);
      }
    }

    return result;
  }
};
// @lc code=end
