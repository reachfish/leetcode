/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array
 *
 * Medium (32.14%)
 * Total Accepted:    169759
 * Total Submissions: 528225
 * Testcase Example:  '[]\n5'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end){
            int mid = (begin+end)/2;
            int val0 = nums[mid];
            
            if(val0 == target){
                return mid;
            }
            
            int val1 = nums[begin];
            int val2 = nums[end];
            
            if(val1 < val2){
                if(target < val0){
                    end = mid - 1;
                }
                else{
                    begin = mid + 1;
                }
            }
            else if(val0 >= val1){
                if (target >= val1 && target < val0){
                    end = mid - 1;
                }
                else{
                    begin = mid + 1;   
                }
            }
            else{
                if (target > val0 && target <= val2){
                    begin = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
            
        }
        
        return -1;
    }
};
