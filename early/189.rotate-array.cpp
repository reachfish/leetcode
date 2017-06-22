/*
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array
 *
 * Easy (24.28%)
 * Total Accepted:    126182
 * Total Submissions: 519600
 * Testcase Example:  '[1]\n0'
 *
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to
 * [5,6,7,1,2,3,4]. 
 * 
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * 
 * 
 * [show hint]
 * Hint:
 * Could you do it in-place with O(1) extra space?
 * 
 * 
 * Related problem: Reverse Words in a String II
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    void reverse(vector<int>& nums, int i, int j){
        while(i<j) { swap(nums[i++], nums[j--]); }
    }
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()) { return; }
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};
