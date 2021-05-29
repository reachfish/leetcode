/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (49.98%)
 * Likes:    3064
 * Dislikes: 79
 * Total Accepted:    461.1K
 * Total Submissions: 917K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    dp(0, nums, result);
    return result;
  }

  void dp(int i, vector<int>& nums, vector<vector<int>>& result) {
    if (i == nums.size()) {
      result.push_back(nums);
      return;
    }

    unordered_set<int> exists;
    for (int j = i; j < nums.size(); j++) {
      if (exists.count(nums[j])) {
        continue;
      }

      exists.insert(nums[j]);
      std::swap(nums[i], nums[j]);
      dp(i + 1, nums, result);
      std::swap(nums[i], nums[j]);
    }
  }
};
// @lc code=end
