/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (63.33%)
 * Likes:    4651
 * Dislikes: 92
 * Total Accepted:    658.9K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sample;

        helper(result, sample, nums, 0);

        return result;
    }

    void helper(vector<vector<int>>& result, vector<int>& sample, const vector<int>& nums, int i) {
        if (i == nums.size()) {
            result.push_back(sample);
            return;
        }
        size_t size = sample.size();
        helper(result, sample, nums, i + 1);

        sample.resize(size);
        sample.push_back(nums[i]);
        helper(result, sample, nums, i + 1);
    }
};
// @lc code=end
