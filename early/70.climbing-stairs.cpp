/*
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs
 *
 * Easy (39.59%)
 * Total Accepted:    173186
 * Total Submissions: 437457
 * Testcase Example:  '1'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * 
 * Note: Given n will be a positive integer.
 * 
 */
class Solution {
public:
    int climbStairs(int n) {
        if(n<0){
            return 0;
        }
        
        if(n==1){
            return 1;
        }
        
        if(n==2){
            return 2;
        }
        
        int a = 1, b = 2;
        for(int i=3;i<=n;i++){
            int tmp = b;
            b += a;
            a = tmp;
        }
        
        return b;
    }
};
