/*
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range
 *
 * Medium (33.71%)
 * Total Accepted:    54291
 * Total Submissions: 161072
 * Testcase Example:  '0\n0'
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 * 
 * 
 * For example, given the range [5, 7], you should return 4.
 * 
 * 
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bitLen = sizeof(int) * 8;
        int i = bitLen;
        int res = 0;
        
        while(i>=0){
            int a = (m >> i) & 1;
            int b = (n >> i) & 1;
            
            if(a!=b){
                break;
            }
            
            if(a){
                res |= 1 << i;
            }
            
            i--;
        }
        
        
        return res;
    }
};
