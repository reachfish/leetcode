/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (56.55%)
 * Likes:    1556
 * Dislikes: 841
 * Total Accepted:    772K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an integer array nums, return true if any value appears at least twice
 * in the array, and return false if every element is distinct.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> snums;
    for (auto n : nums) {
      if (snums.insert(n).second == false) {
        return true;
      }
    }

    return false;
  }
};
// @lc code=end
