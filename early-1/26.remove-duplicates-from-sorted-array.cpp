/*
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array
 *
 * Easy (35.57%)
 * Total Accepted:    229208
 * Total Submissions: 644440
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted array, remove the duplicates in place such that each element
 * appear only once and return the new length.
 * 
 * 
 * Do not allocate extra space for another array, you must do this in place
 * with constant memory.
 * 
 * 
 * 
 * For example,
 * Given input array nums = [1,1,2],
 * 
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively. It doesn't matter what you leave beyond the new
 * length.
 * 
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        
        vector<int>::iterator prior = nums.begin() + 1;
        vector<int>::iterator post = nums.begin();
        vector<int>::iterator end = nums.end();
        do{
            while(prior!=end && *prior == *post){
                prior++;
            }
            if(prior==end){
                break;
            }
            if (prior != post){
                *++post = *prior++;
            }
        }while(1);
        
        nums.erase(post+1, end);
        
        return nums.size();
    }
};
