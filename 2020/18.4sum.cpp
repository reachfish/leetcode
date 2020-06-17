/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (33.25%)
 * Likes:    1814
 * Dislikes: 313
 * Total Accepted:    324.3K
 * Total Submissions: 975.2K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int i=0; i<nums.size(); i++) {
			if (i>0 && nums[i] == nums[i-1]) {
				continue;
			}

			int start_j = i + 1;
			for (int j=i+1; j<nums.size(); j++) {
				if (j > start_j && nums[j] == nums[j-1]) {
					continue;
				}

				int cur = nums[i] + nums[j] - target;
				for (int k=j+1, m=nums.size() - 1; k<m;) {
					int value = cur + nums[k] + nums[m];
					if (value > 0) {
						--m;
					} else if (value <0) {
						++k;
					} else {
						result.push_back({nums[i], nums[j], nums[k], nums[m]});
						++ k;
						-- m;
						while (k<m && nums[k] == nums[k-1]) { ++k; }
						while (k<m && nums[m] == nums[m+1]) { --m; }
					}
				}
			}
		}

		return result;
    }
};
// @lc code=end
