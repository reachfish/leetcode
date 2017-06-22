/*
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two
 *
 * Easy (39.90%)
 * Total Accepted:    133958
 * Total Submissions: 335739
 * Testcase Example:  '1'
 *
 * 
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n&(n-1));
    }
};
