/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (38.52%)
 * Likes:    1274
 * Dislikes: 1370
 * Total Accepted:    326.5K
 * Total Submissions: 841.9K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an integer array nums and an integer k, return true if there are two
 * distinct indices i and j in the array such that nums[i] == nums[j] and abs(i
 * - j) <= k.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int, int> pos;
    for (int i = 0; i < nums.size(); i++) {
      auto n = nums[i];
      auto it = pos.find(n);
      if (it != pos.end() && i - it->second <= k) {
        return true;
      }
      pos[n] = i;
    }

    return false;
  }
};
// @lc code=end
