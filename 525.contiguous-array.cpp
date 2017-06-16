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
    int findMaxLength(vector<int>& nums) {
        stack<pair<int, int>> stk;
        for(int i=0;i<nums.size();i++) {
            int num = nums[i];
            if(stk.empty()||stk.top().first==num) { stk.push(make_pair(num, i)); }
            else { stk.pop(); }
        }

        int max = 0;
        int last = nums.size();
        while(!stk.empty()) {
            int i = stk.top().second;
            printf("(%d,%d)", i, nums[i]);
            max = max > (last-i-1) ? max : (last-i-1);
            last = i;
            stk.pop();
        }
        max = max > last ? max : last;

        return max;
    }
};
