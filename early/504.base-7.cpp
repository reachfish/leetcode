/*
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7
 *
 * Easy (45.04%)
 * Total Accepted:    14883
 * Total Submissions: 33042
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */
class Solution {
public:
    string convertToBase7(int num) {
        bool isNeg = num < 0;
        if(num < 0){
            num = - num;
        }
        
        string s;
        do{
            s = string(1, '0' + num%7) + s;
            num /= 7;
        }while(num);
        
        if(isNeg){
            s = "-" + s;
        }
        
        return s;
    }
};
