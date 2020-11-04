/*
 * @lc app=leetcode id=15 lang=golang
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.18%)
 * Total Accepted:    571.8K
 * Total Submissions: 2.4M
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
import "sort"
func threeSum(nums []int) [][]int {
	result := make([][]int, 0)
	sort.Ints(nums)
	for i, n1 := range(nums) {
		if i > 0 && n1 == nums[i-1] {
			continue
		}
		target := 0 - n1
		for j, k := i + 1, len(nums)-1; j < k; {
			sum2 := nums[j] + nums[k]
			if target == sum2 {
				result = append(result, []int{ nums[i], nums[j], nums[k]})
				j++
				k--
			} else if target < sum2 {
				k--
			} else {
				j++
			}
			if target >= sum2 {
				for ; j<k && nums[j] == nums[j-1]; j++ {
				}
			}
			if target <= sum2 {
				for ; j<k && nums[k] == nums[k+1]; k-- {
				}
			}
		}
	}

	return result
}
