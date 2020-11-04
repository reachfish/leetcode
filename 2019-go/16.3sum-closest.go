/*
 * @lc app=leetcode id=16 lang=golang
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.77%)
 * Total Accepted:    355.3K
 * Total Submissions: 776.3K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
import "sort"
func threeSumClosest(nums []int, target int) int {
	sum := 0
	minDiff := -1
	sort.Ints(nums)
	for i, n1 := range(nums) {
		v := n1 - target
		for j, k := i + 1, len(nums) - 1; j < k; {
			diff := v + nums[j] + nums[k]
			if diff == 0 {
				return target
			} else if diff > 0 {
				if diff < minDiff || minDiff == -1 {
					minDiff = diff
					sum = nums[i] + nums[j] + nums[k]
				}
				k--
			} else {
				diff = -diff
				if diff < minDiff || minDiff == -1 {
					minDiff = diff
					sum = nums[i] + nums[j] + nums[k]
				}
				j++
			}
		}
	}

	return sum
}
