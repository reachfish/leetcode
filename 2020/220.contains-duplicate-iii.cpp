/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (21.33%)
 * Likes:    1552
 * Dislikes: 1638
 * Total Accepted:    168.2K
 * Total Submissions: 787.5K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * Given an integer array nums and two integers k and t, return true if there
 * are two distinct indices i and j in the array such that abs(nums[i] -
 * nums[j]) <= t and abs(i - j) <= k.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,1], k = 3, t = 0
 * Output: true
 * Example 2:
 * Input: nums = [1,0,1,1], k = 1, t = 2
 * Output: true
 * Example 3:
 * Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^4
 * 0 <= t <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> snums;
    for (int i = 0; i < nums.size(); i++) {
      if (i > k) {
        snums.erase(nums[i - k - 1]);
      }
      auto n = nums[i];
      auto pr = snums.insert(n);
      if (pr.second == false) {
        return true;
      }

      auto it = pr.first;
      if (it != snums.begin()) {
        it--;
        if ((int64_t)n - *it <= t) {
          return true;
        }
      }

      it = pr.first;
      it++;
      if (it != snums.end() && *it - (int64_t)n <= t) {
        return true;
      }
    }

    return false;
  }
};
// @lc code=end
