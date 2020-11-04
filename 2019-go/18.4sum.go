/*
 * @lc app=leetcode id=18 lang=golang
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (30.77%)
 * Total Accepted:    240.6K
 * Total Submissions: 781.8K
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
func fourSum(nums []int, target int) [][]int {
	result := make([][]int, 0)
	sort.Ints(nums)
	size := len(nums)
	for i:= 0; i<size; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i+1; j<size; j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}
			for r, s := j+1, size - 1; r<s; {
				sum := nums[i] + nums[j] + nums[r] + nums[s]
				if sum == target {
					result = append(result, []int{nums[i], nums[j], nums[r], nums[s]})
					r++
					s--
					for ; r<s && nums[r] == nums[r-1]; r++ {
					}
					for ; r<s && nums[s] == nums[s+1]; s-- {
					}
				} else if sum < target {
					r++
					for ; r<s && nums[r] == nums[r-1]; r++ {
					}
				} else {
					s--
					for ; r<s && nums[s] == nums[s+1]; s-- {
					}
				}
			}
		}
	}

	return result
}
