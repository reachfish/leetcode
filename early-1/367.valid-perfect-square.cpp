/*
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square
 *
 * Easy (37.99%)
 * Total Accepted:    42737
 * Total Submissions: 112481
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * 
 * Example 1:
 * 
 * Input: 16
 * Returns: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 14
 * Returns: False
 * 
 * 
 * 
 * Credits:Special thanks to @elmirap for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<0){
            return false;
        }
        
        if(num==0){
            return true;
        }
        
        int len = 0;
        int n = num;
        while(n){
            len++;
            n >>= 1;
        }
        
        int i = 1<<(len/2-1);
        i = i < 0 ? 1 : i;
        int j = 1<<(len/2+1);
        int mid;
        while(i<j){
            mid = (i+j)/2;
            int val = mid * mid;
            if(val==num){
                return true;
            }
            else if(val < num){
                i++;
            }
            else{
                j--;
            }
        }
        
        return i*i == num;
    }
};
