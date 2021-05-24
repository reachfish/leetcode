/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (45.03%)
 * Likes:    4420
 * Dislikes: 94
 * Total Accepted:    286.3K
 * Total Submissions: 635.1K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array nums containing only positive integers, find if the
 * array can be partitioned into two subsets such that the sum of elements in
 * both subsets is equal.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    bitset<100 * 200 + 1> bs(1);
    int sum = 0;
    for (auto num : nums) {
      sum += num;
      bs |= bs << num;
    }

    return !(sum & 1) && bs[sum >> 1];
  }
};
// @lc code=end
