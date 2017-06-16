/*
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array
 *
 * Medium (37.30%)
 * Total Accepted:    8815
 * Total Submissions: 23638
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array, find the maximum length of a contiguous subarray with
 * equal number of 0 and 1. 
 * 
 * 
 * Example 1:
 * 
 * Input: [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of
 * 0 and 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 * 
 * 
 * 
 * Note:
 * The length of the given binary array will not exceed 50,000.
 * 
 */
class Solution {
public:
    //使用栈方式是错误的，[1,0,1,1,0,1]会出错
    int findMaxLength(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) { 
            if(!nums[i]) nums[i] = -1;
        }

        map<int, int> m;
        int sum = 0;
        int max = 0;
        m[0] = -1;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(m.count(sum)){
                max = max > (i - m[sum]) ? max : (i-m[sum]);
            }
            else{
                m[sum] = i;
            }
        }

        return max;
    }
};
