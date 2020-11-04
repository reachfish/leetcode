/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number
 *
 * Easy (34.91%)
 * Total Accepted:    213427
 * Total Submissions: 611395
 * Testcase Example:  '-2147483648'
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * click to show spoilers.
 * 
 * Some hints:
 * 
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the
 * restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the
 * problem "Reverse Integer", you know that the reversed integer might
 * overflow. How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0) { return false; }
       if(x < 10) { return true; }
       
       int power = 10;
       while(power <= x/10) power *= 10;
       
       while(x>9){
           if(x/power != x%10) { return false; }
           x -= x/power * power;
           power /= 100;
           x /= 10;
       }
       
       return power <= 1 || x == 0;
    }
};
