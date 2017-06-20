/*
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii
 *
 * Medium (33.69%)
 * Total Accepted:    55012
 * Total Submissions: 163250
 * Testcase Example:  '[]'
 *
 * Note: This is an extension of House Robber.
 * 
 * After robbing those houses on that street, the thief has found himself a new
 * place for his thievery so that he will not get too much attention. This
 * time, all houses at this place are arranged in a circle. That means the
 * first house is the neighbor of the last one. Meanwhile, the security system
 * for these houses remain the same as for those in the previous street. 
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:

    int max(int a, int b){
        return a > b ? a : b;
    }

    int robInt(vector<int>& nums, int s, int e){
        int m = 0;
        int a = 0, b = 0;
        for(int i = s; i<= e; i++){
            if(i & 1){
                a = max(b, a + nums[i]);
                m = max(a, m);
            }
            else{
                b = max(a, b + nums[i]);
                m = max(b, m);
            }
        }

        return m;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) { return nums[0]; }
        return max(robInt(nums, 0, nums.size() - 2), robInt(nums, 1, nums.size() - 1));    
    }
};
