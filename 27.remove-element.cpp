/*
 * [27] Remove Element
 *
 * https://leetcode.com/problems/remove-element
 *
 * algorithms
 * Easy (38.94%)
 * Total Accepted:    213.4K
 * Total Submissions: 546.5K
 * Testcase Example:  '[3,2,2,3]\n3'
 *
 * Given an array and a value, remove all instances of that value in place and
 * return the new length.
 * 
 * 
 * Do not allocate extra space for another array, you must do this in place
 * with constant memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 * 
 * 
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 * 
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 2.
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int k = 0;        
		for(int i=0;i<nums.size(); i++){
			if(nums[i]!=val){
				nums[k++] = nums[i];
			}
		}

		nums.erase(nums.begin() + k, nums.end());

		return nums.size();
    }
};
