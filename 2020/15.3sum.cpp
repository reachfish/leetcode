/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (26.29%)
 * Likes:    6724
 * Dislikes: 798
 * Total Accepted:    895.3K
 * Total Submissions: 3.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		std::vector<std::vector<int>> result;
		std::sort(nums.begin(), nums.end());
		for (int i=0; i< nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i-1]) {
				continue;
			}
			for (int j=i+1, k=nums.size() -1; j<k;) {
				int value = nums[i] + nums[j] + nums[k];
				if (value > 0) {
					-- k;
				} else if (value < 0) {
					++ j;
				} else {
					result.push_back({nums[i], nums[j], nums[k]});
					++ j;
					-- k;
					while (j<k && nums[j] == nums[j-1]) {
						++ j;
					}
					while (j<k && nums[k] == nums[k+1]) {
						-- k;
					}
				}
			}
		}

		return result;
    }
};
// @lc code=end
