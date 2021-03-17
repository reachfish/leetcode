/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (30.50%)
 * Likes:    2862
 * Dislikes: 306
 * Total Accepted:    240.9K
 * Total Submissions: 783.7K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non-negative integers nums, arrange them such that they form
 * the largest number.
 *
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,2]
 * Output: "210"
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,30,34,5,9]
 * Output: "9534330"
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1]
 * Output: "1"
 *
 *
 * Example 4:
 *
 *
 * Input: nums = [10]
 * Output: "10"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> vs;
    vs.reserve(nums.size());
    for (auto n : nums) {
      vs.push_back(std::to_string(n));
    }

    sort(vs.begin(), vs.end(), [](const string& a, const string& b) -> bool {
      return a + b > b + a;
    });

    string r;
    for (const auto& s : vs) {
      r += s;
    }

    if (!r.empty() && r.front() == '0') {
      r = "0";
    }

    return r;
  }
};
// @lc code=end
