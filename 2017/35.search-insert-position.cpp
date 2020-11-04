/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position
 *
 * Easy (39.53%)
 * Total Accepted:    173141
 * Total Submissions: 437988
 * Testcase Example:  '[1]\n0'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * 
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        
        while(i<=j){
            int mid = (i+j)/2;
            int val = nums[mid];
            if (val == target){
                return mid;
            }
            
            if(target < val){
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        
        return j + 1;
    }
};
