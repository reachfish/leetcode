/*
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four
 *
 * Easy (38.23%)
 * Total Accepted:    62693
 * Total Submissions: 163975
 * Testcase Example:  '16'
 *
 * 
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example:
 * Given num = 16, return true.
 * Given num = 5, return false.
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 * 
 * Credits:Special thanks to @yukuairoy  for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<0) { return false; }
        while(num && !(num&3)){
            num >>= 2;
        }
        
        return num == 1;
    }
};
