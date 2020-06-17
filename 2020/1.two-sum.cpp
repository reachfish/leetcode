/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (45.46%)
 * Likes:    15231
 * Dislikes: 555
 * Total Accepted:    3M
 * Total Submissions: 6.5M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		struct NumIndex {
			int n;
			int i;

			bool operator<(const NumIndex& other) const {
				if (n != other.n) {
					return n < other.n;
				}
				return i < other.i;
			}
		};
		vector<NumIndex> ext_nums;
		ext_nums.reserve(nums.size());
		for (int i=0; i<nums.size(); i++) {
			ext_nums.push_back({nums[i], i});
		}
		sort(ext_nums.begin(), ext_nums.end());
		for (int i=0, j=ext_nums.size() - 1; i<j; ) {
			int diff = ext_nums[i].n + ext_nums[j].n - target;
			if (diff > 0) {
				--j;
			} else if (diff < 0) {
				++i;
			} else {
				return {ext_nums[i].i, ext_nums[j].i};
			}
		}

		return {};
    }
};
// @lc code=end
