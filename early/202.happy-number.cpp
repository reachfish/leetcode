/*
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number
 *
 * Easy (40.27%)
 * Total Accepted:    121599
 * Total Submissions: 301971
 * Testcase Example:  '1'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 19 is a happy number
 * 
 * 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 * 
 * Credits:Special thanks to @mithmatt and @ts for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    bool isHappy(int n) {
        if(n<=0) { return false; }
        set<int> st;
        
        while(true){
            if(n==1) { return true; }
            if(st.count(n)) { return false; }
            st.insert(n);
            
            int tmp = 0;
            while(n){
                tmp += (n%10) * (n%10);
                n /= 10;
            }
            
            n = tmp;
        }
    }
};
