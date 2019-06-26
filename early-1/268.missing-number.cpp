/*
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number
 *
 * Easy (44.10%)
 * Total Accepted:    114552
 * Total Submissions: 259770
 * Testcase Example:  '[0]'
 *
 * 
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * 
 * For example,
 * Given nums = [0, 1, 3] return 2.
 * 
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int ss = 0;
        for(int i=0;i<nums.size();i++){
            ss += i;
            sum += nums[i];
        }
        
        ss += nums.size();
        
        return ss - sum;
    }
};
