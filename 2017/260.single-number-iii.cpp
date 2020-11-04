/*
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii
 *
 * Medium (50.95%)
 * Total Accepted:    65549
 * Total Submissions: 128663
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * 
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * 
 * For example:
 * 
 * 
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 * 
 * 
 * Note:
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        if(nums.size()<2){
            return res;
        }
        
        int val = 0;
        for(int i=0;i<nums.size();i++){
            val ^= nums[i];
        }
        
        int d = 0;
        while(d<32&&!(val&(1<<d))){
            d++;
        }
        
        if(d==32){
            return res;
        }
        
        int val1 = 0, val2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&(1<<d)){
                val1 ^= nums[i];
            }
            else{
                val2 ^= nums[i];
            }
        }
        
        res.push_back(val1);
        res.push_back(val2);
        
        return res;
    }
};
