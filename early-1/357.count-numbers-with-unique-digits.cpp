/*
 * [357] Count Numbers with Unique Digits
 *
 * https://leetcode.com/problems/count-numbers-with-unique-digits
 *
 * Medium (45.76%)
 * Total Accepted:    33182
 * Total Submissions: 72508
 * Testcase Example:  '2'
 *
 * Given a non-negative integer n, count all numbers with unique digits, x,
 * where 0 ≤ x < 10n.
 * 
 * 
 * ⁠   Example:
 * Given n = 2, return 91. (The answer should be the total numbers in the range
 * of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
 * 
 * 
 * Credits:Special thanks to @memoryless for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n<0){
            return 0;
        }
        
        int cur = 9;
        int total = 1;
        
        for(int i=1;i<=n&&i<=10;i++){
            total += cur;
            cur *= (10-i);
        }
        
        return total;
    }
};
