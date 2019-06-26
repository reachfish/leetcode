/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.26%)
 * Total Accepted:    1.9M
 * Total Submissions: 4.3M
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

package main

import "sort"

type NumWithIndex struct {
	value int
	index int
}

func twoSum(nums []int, target int) []int {
	nlen := len(nums)
	if nlen < 2 {
		return []int{}
	}

	numsWithIndex := make([]NumWithIndex, nlen)
	for i := 0 ; i < nlen; i++ {
		numsWithIndex[i] = NumWithIndex{ nums[i], i}
	}
	sort.Slice(numsWithIndex, func(i, j int) bool { return numsWithIndex[i].value < numsWithIndex[j].value })
	for i, j := 0, nlen -1; i < j ; {
		sum := numsWithIndex[i].value + numsWithIndex[j].value
		if sum < target {
			i += 1
		} else if sum > target {
			j -= 1
		} else {
			return []int{numsWithIndex[i].index, numsWithIndex[j].index}
		}
	}

	return []int{}
}
