/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.86%)
 * Likes:    2017
 * Dislikes: 138
 * Total Accepted:    464.7K
 * Total Submissions: 1M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 =
 * 2).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int sum = 0;
		int close = -1;
		sort(nums.begin(), nums.end());
		for (int i=0; i<nums.size(); i++) {
			for (int j=i+1, k=nums.size() - 1; j<k;) {
				int value = nums[i] + nums[j] + nums[k] - target;
				if (value == 0) {
					return target;
				}
				int diff = abs(value);
				if (close < 0 || diff < close) {
					close = diff;
					sum = value + target;
				}
				if (value > 0) {
					--k;
				} else {
					++j;
				}
			}
		}

		return sum;
    }
};
// @lc code=end
