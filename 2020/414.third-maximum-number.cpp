/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (30.76%)
 * Likes:    1019
 * Dislikes: 1756
 * Total Accepted:    228.1K
 * Total Submissions: 741K
 * Testcase Example:  '[3,2,1]'
 *
 * Given integer array nums, return the third maximum number in this array. If
 * the third maximum does not exist, return the maximum number.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,2,1]
 * Output: 1
 * Explanation: The third maximum is 1.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2]
 * Output: 2
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [2,2,3,1]
 * Output: 1
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 * Follow up: Can you find an O(n) solution?
 */

// @lc code=start
class Solution {
 public:
  struct OptNum {
    int num;
    bool valid;
  };

  int thirdMax(vector<int>& nums) {
    std::vector<OptNum> max(3, {0, false});

    for (auto num : nums) {
      for (int i = 0; i < 3; i++) {
        if (!max[i].valid) {
          max[i] = {num, true};
          break;
        }

        if (num > max[i].num) {
          for (int j = 2; j > i; j--) {
            max[j] = max[j - 1];
          }
          max[i] = {num, true};
          break;
        } else if (num == max[i].num) {
          break;
        }
      }
    }

    if (max[2].valid) {
      return max[2].num;
    }

    if (max[1].valid) {
      return std::max(max[0].num, max[1].num);
    }

    return max[0].num;
  }
};
// @lc code=end
