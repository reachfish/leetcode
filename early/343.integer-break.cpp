/*
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break
 *
 * Medium (45.63%)
 * Total Accepted:    41620
 * Total Submissions: 91212
 * Testcase Example:  '2'
 *
 * 
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * 
 * 
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10
 * = 3 + 3 + 4).
 * 
 * 
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int integerBreak(int n) {
        if(n<2){
            return -1;
        }
        
        if(n==2){
            return 1;
        }
        
        if(n==3){
            return 2;
        }
        
        int res = 1;
        int power = n/3;
        int left = n%3;
        if(left==1){
            res = 4;
            power--;
        }
        else if(left==2){
            res = 2;
        }
        
        for(int i=0;i<power;i++){
            res *= 3;
        }
        
        return res;
    }
};
