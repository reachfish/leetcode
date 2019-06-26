/*
 * [507] Perfect Number
 *
 * https://leetcode.com/problems/perfect-number
 *
 * Easy (33.43%)
 * Total Accepted:    8657
 * Total Submissions: 25896
 * Testcase Example:  '28'
 *
 * We define the Perfect Number is a positive integer that is equal to the sum
 * of all its positive divisors except itself. 
 * 
 * Now, given an integer n, write a function that returns true when it is a
 * perfect number and false when it is not.
 * 
 * 
 * Example:
 * 
 * Input: 28
 * Output: True
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * 
 * 
 * 
 * Note:
 * The input number n will not exceed 100,000,000. (1e8)
 * 
 */
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=1)
        {
            return false;
        }
        
        int sum = 0;
        double root = sqrt(num);
        for(int i = 1;i <= root; i++){
            if(num%i==0){
                sum += i;
                if(i!=1 && i!=root){
                    sum += num/i;
                }
                
                if(sum > num){
                    return false;
                }
            }
        }
        
        return sum == num;
    }
};
