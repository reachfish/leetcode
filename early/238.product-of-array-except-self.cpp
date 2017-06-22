/*
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self
 *
 * Medium (48.55%)
 * Total Accepted:    97543
 * Total Submissions: 200906
 * Testcase Example:  '[0,0]'
 *
 * 
 * Given an array of n integers where n > 1, nums, return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Solve it without division and in O(n).
 * 
 * For example, given [1,2,3,4], return [24,12,8,6].
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array
 * does not count as extra space for the purpose of space complexity analysis.)
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        int zeroIndex = 0;
        int all = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                all *= nums[i];
            }
            else{
                zeroCount++;
                zeroIndex = i;
                if(zeroCount>=2){
                    break;
                }
            }
        }
        
        if(zeroCount>=1){
            vector<int> ret(nums.size(), 0);
            if(zeroCount==1){
                ret[zeroIndex] = all;
            }
            
            return ret;
        }
        
        
        vector<int> ret(nums.size());
        for(int i=0;i<nums.size();i++){
            ret[i] = all/nums[i];
        }
        
        return ret;
    }
};
