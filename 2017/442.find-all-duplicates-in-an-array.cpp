/*
 * [442] Find All Duplicates in an Array
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array
 *
 * Medium (54.62%)
 * Total Accepted:    28483
 * Total Submissions: 52139
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
 * appear twice and others appear once.
 * 
 * Find all the elements that appear twice in this array.
 * 
 * Could you do it without extra space and in O(n) runtime?
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [2,3]
 * 
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){
                continue;
            }
            
            int j = nums[i];
            nums[i] = 0;
            
            while(1){
                int k = j - 1;
                if(nums[k]<=0){
                    nums[k]--;
                    break;
                }
                else{
                    j = nums[k];
                    nums[k] = -1;
                }
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==-2){
                ret.push_back(i+1);
            }
        }
        
        return ret;
    }
};
