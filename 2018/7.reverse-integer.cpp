/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer
 *
 * algorithms
 * Easy (24.34%)
 * Total Accepted:    273.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '0'
 *
 * Reverse digits of an integer.
 * 
 * 
 * Example1: x =  123, return  321
 * Example2: x = -123, return -321
 * 
 * 
 * click to show spoilers.
 * 
 * Have you thought about this?
 * 
 * Here are some good questions to ask before coding. Bonus points for you if
 * you have already thought through this!
 * 
 * If the integer's last digit is 0, what should the output be? ie, cases such
 * as 10, 100.
 * 
 * Did you notice that the reversed integer might overflow? Assume the input is
 * a 32-bit integer, then the reverse of 1000000003 overflows. How should you
 * handle such cases?
 * 
 * For the purpose of this problem, assume that your function returns 0 when
 * the reversed integer overflows.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * The input is assumed to be a 32-bit signed integer. Your function should
 * return 0 when the reversed integer overflows.
 * 
 */
class Solution {
public:
    int reverse(int x) {
		int signal = x > 0 ? 1 : -1;        
		x = abs(x);

		long y = 0;
		while(x){
			y = y*10 + x%10;
			x /= 10;
		}

		y *= signal;
		if(y != static_cast<int>(y)){
			return 0;
		}

		return y;
    }
};
