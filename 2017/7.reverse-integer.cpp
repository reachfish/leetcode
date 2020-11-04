/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer
 *
 * Easy (24.19%)
 * Total Accepted:    247795
 * Total Submissions: 1024201
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
        bool isNeg = x < 0;
        if(x<0){
            x = -x;
        }
        if(x<0){
            return 0;
        }
        
        int res = 0;
        while(x){
            int val = 10 * res + x % 10;
            if(val/10<res){
                return 0;
            }
            
            res = val;
            x /= 10;
            cout<<res<<endl;
        }
        if(res<0){
            return 0;
        }
        
        if(isNeg){
            res = - res;
        }
        
        return res;
    }
};
