/*
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii
 *
 * Medium (41.07%)
 * Total Accepted:    115362
 * Total Submissions: 280897
 * Testcase Example:  '[1]'
 *
 * 
 * Given an array of integers, every element appears three times except for
 * one, which appears exactly once. Find that single one.
 * 
 * 
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<32;i++){
            int d = 0;
            for(int j=0;j<nums.size();j++){
                d += (nums[j] >> i) & 1;
            }
            
            res |= (d%3) << i;
        }
        
        return res;
    }
};
