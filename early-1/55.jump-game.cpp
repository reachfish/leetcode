/*
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game
 *
 * Medium (29.43%)
 * Total Accepted:    121454
 * Total Submissions: 412756
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * 
 * Each element in the array represents your maximum jump length at that
 * position. 
 * 
 * 
 * Determine if you are able to reach the last index.
 * 
 * 
 * 
 * For example:
 * A = [2,3,1,1,4], return true.
 * 
 * 
 * A = [3,2,1,0,4], return false.
 * 
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool can = true;
        int left = 1;
        for(int i=0;i<nums.size();i++){
            if(left<=0){
                can = false;
                break;
            }
            
            left--;
            left = left > nums[i] ? left :nums[i];
        }
        
        return can;
    }
};
