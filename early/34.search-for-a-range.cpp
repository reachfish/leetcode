/*
 * [34] Search for a Range
 *
 * https://leetcode.com/problems/search-for-a-range
 *
 * Medium (31.23%)
 * Total Accepted:    135178
 * Total Submissions: 432903
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers sorted in ascending order, find the starting and
 * ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * 
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 * 
 */
class Solution {
public:
    int search(const vector<int>& nums, int target, bool first){
        if(nums.empty()){
            return -1;
        }
        
        int i = 0;
        int j = nums.size() - 1;
        
        while(i<j){
            int mid = first ? (i+j)/2 : (i+j+1)/2;
            if(target < nums[mid]){
                j = mid - 1;
            }
            else if(target > nums[mid]){
                i = mid + 1;
            }
            else{
                if(first){
                    j = mid;
                }
                else{
                    i = mid;
                }
            }
        }
        
        if(i==j&&nums[i]==target){
            return i;
        }
        
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = search(nums, target, true);
        int right = left == -1 ? -1 : search(nums, target, false);
        
        vector<int> res;
        res.push_back(left);
        res.push_back(right);
        
        return res;
    }
};
