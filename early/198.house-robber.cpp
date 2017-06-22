/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber
 *
 * Easy (38.49%)
 * Total Accepted:    134104
 * Total Submissions: 348433
 * Testcase Example:  '[]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Also thanks to @ts for adding additional test cases.
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int max = 0;
        int dp[4];
        
        for(int i=0;i<nums.size();i++){
            int cur = 0;
            
            if(i >= 2){
                cur = dp[(i-2)%4];
            }
            if(i >= 3){
                int n = dp[(i-3)%4];
                cur = cur > n ? cur : n;
            }
            cur += nums[i];
            max = max > cur ? max : cur;
            
            dp[i%4] = cur;
        }
        
        return max;
    }
};
