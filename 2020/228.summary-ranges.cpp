/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Easy (42.20%)
 * Likes:    962
 * Dislikes: 694
 * Total Accepted:    209.6K
 * Total Submissions: 491.6K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * You are given a sorted unique integer array nums.
 *
 * Return the smallest sorted list of ranges that cover all the numbers in the
 * array exactly. That is, each element of nums is covered by exactly one of
 * the ranges, and there is no integer x such that x is in one of the ranges
 * but not in nums.
 *
 * Each range [a,b] in the list should be output as:
 *
 *
 * "a->b" if a != b
 * "a" if a == b
 *
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: The ranges are:
 * [0,2] --> "0->2"
 * [4,5] --> "4->5"
 * [7,7] --> "7"
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: The ranges are:
 * [0,0] --> "0"
 * [2,4] --> "2->4"
 * [6,6] --> "6"
 * [8,9] --> "8->9"
 *
 *
 * Example 3:
 *
 *
 * Input: nums = []
 * Output: []
 *
 *
 * Example 4:
 *
 *
 * Input: nums = [-1]
 * Output: ["-1"]
 *
 *
 * Example 5:
 *
 *
 * Input: nums = [0]
 * Output: ["0"]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 20
 * -2^31 <= nums[i] <= 2^31 - 1
 * All the values of nums are unique.
 * nums is sorted in ascending order.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }

    int start = nums[0];
    vector<string> result;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1] + 1) {
        putRange(start, nums[i - 1], result);
        start = nums[i];
      }
    }

    putRange(start, nums.back(), result);
    return result;
  }

  void putRange(int start, int end, vector<string>& result) {
    if (start == end) {
      result.push_back(std::to_string(start));
    } else {
      result.push_back(std::to_string(start) + "->" + std::to_string(end));
    }
  }
};
// @lc code=end
