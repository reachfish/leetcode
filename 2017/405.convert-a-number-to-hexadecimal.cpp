/*
 * [405] Convert a Number to Hexadecimal
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal
 *
 * Easy (40.93%)
 * Total Accepted:    22235
 * Total Submissions: 54329
 * Testcase Example:  '26'
 *
 * 
 * Given an integer, write an algorithm to convert it to hexadecimal. For
 * negative integer, two’s complement method is used.
 * 
 * 
 * Note:
 * 
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is
 * zero, it is represented by a single zero character '0'; otherwise, the first
 * character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You must not use any method provided by the library which converts/formats
 * the number to hex directly.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 26
 * 
 * Output:
 * "1a"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * -1
 * 
 * Output:
 * "ffffffff"
 * 
 * 
 */
class Solution {
public:
    string toHex(int num) {
        int bits[32];
        memset(bits, 0, 32 * 4);

        if(num==0x80000000){
            num = 0;
            bits[31] = 1;
        }
        
        bool isNeg = num < 0;
        if(num < 0) num = - num;
        int i = -1;
        int oneIdx = -1;
        while(num){
            bits[++i] = num & 1;
            num >>= 1;
            if(oneIdx < 0 && bits[i]) { oneIdx = i; }
        }
        if(isNeg) {
            for(int i=oneIdx+1;i<32;i++) { bits[i] = 1 - bits[i]; }
        }
        
        string s;
        for(int i=28;i>=0;i-=4){
            int val = 0;
            int power = 1;
            for(int j=0;j<4;j++){
                val += bits[i+j] * power;
                power *= 2;
            }
            if(val || !s.empty() || i == 0){
                s += string(1, val < 10 ? '0' + val : 'a' + val - 10); 
            }
        }
        
        return s;
    }
};
