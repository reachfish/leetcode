/*
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii
 *
 * Medium (32.24%)
 * Total Accepted:    57289
 * Total Submissions: 177712
 * Testcase Example:  '1'
 *
 * 
 * Write a program to find the n-th ugly number.
 * 
 * 
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * 
 * 
 * Note that 1 is typically treated as an ugly number, and n does not exceed
 * 1690.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    void insert(vector<long>& a, long val){
        a.insert(lower_bound(a.begin(), a.end(), val), val);
    }
    
    int nthUglyNumber(int n) {
        if(n<=0){
            return -1;
        }
        
        vector<long> a;
        vector<long> b;
        vector<long> c;
        
        a.push_back(2);
        b.push_back(3);
        c.push_back(5);
        
        int res = 1;
        while(--n){
            if(a[0]<b[0]&&a[0]<c[0]){
                res = a[0];
                a.erase(a.begin());
                insert(a, res * 2L);
                insert(b, res * 3L);
                insert(c, res * 5L);
            }
            else if(b[0]<a[0]&&b[0]<c[0]){
                res = b[0];
                b.erase(b.begin());
                insert(b, res * 3L);
                insert(c, res * 5L);
            }
            else{
                res = c[0];
                c.erase(c.begin());
                insert(c, res * 5L);
            }
            
        }
        
        return res;
    }
};
