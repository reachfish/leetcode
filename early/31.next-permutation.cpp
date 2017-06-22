/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation
 *
 * Medium (28.66%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1]'
 *
 * 
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation
 *
 * Medium (28.65%)
 * Total Accepted:    109109
 * Total Submissions: 380832
 * Testcase Example:  '[1]'
 *
 * 
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while(i>=0 && nums[i] >= nums[i+1]) i--;
        if(i < 0){
            i = 0;
            int j = n - 1;
            while(i<j) { swap(nums[i++], nums[j--]); }
        }
        else{
            int j = n - 1;
            while(nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);

            i++;
            j = n - 1;
            while(i<j) { swap(nums[i++], nums[j--]); }
        }
    }
};

