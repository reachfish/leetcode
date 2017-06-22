/*
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers
 *
 * Easy (51.23%)
 * Total Accepted:    69057
 * Total Submissions: 134805
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * Example:
 * Given a = 1 and b = 2, return 3.
 * 
 * 
 * Credits:Special thanks to @fujiaozhu for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int getSum(int a, int b) {
        int c;
        int d;
        do{
            c = a & b;
            d = a ^ b;
            a = c << 1;
            b = d;
        }while(c);
        
        return b;
    }
};
