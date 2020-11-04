/*
 * [80] Remove Duplicates from Sorted Array II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
 *
 * Medium (35.63%)
 * Total Accepted:    116001
 * Total Submissions: 325567
 * Testcase Example:  '[]'
 *
 * 
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * 
 * 
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * 
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new
 * length.
 * 
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = nums.size() - 1;
        int j = nums.size() - 1;
        while(i>=0){
            j = i;
            while(j&&nums[j-1]==nums[j]){
                j--;
            }
            
            if(i-j+1>2){
                nums.erase(nums.begin()+j+2, nums.begin()+i+1);
            }
            
            i = j - 1;
        }
        
        return nums.size();
    }
};
