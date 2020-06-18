/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (62.46%)
 * Likes:    3704
 * Dislikes: 104
 * Total Accepted:    590.5K
 * Total Submissions: 945.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		iterate(result, nums, 0);
		return result;
    }

	void iterate(vector<vector<int>>& result, vector<int>& nums, int idx) {
		if (idx == nums.size()) {
			result.push_back(nums);
			return;
		}

		for (int i=idx; i<nums.size(); i++) {
			swap(nums[idx], nums[i]);
			iterate(result, nums, idx + 1);
			swap(nums[idx], nums[i]);
		}
	}
};
// @lc code=end
