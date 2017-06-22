/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes
 *
 * Easy (26.45%)
 * Total Accepted:    113583
 * Total Submissions: 429496
 * Testcase Example:  '0'
 *
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        
        vector<int> a(n);
        for(int i=2;i<n;i++){
            a[i] = 1;
        }
        
        
        int count = 0;
        for(int i=2;i<n;i++){
            if(!a[i]){
                continue;
            }
            
            count++;
            for(int j=2;i<=(n-1)/j;j++){
                a[i*j] = 0;
            }
        }
        
        return count;
    }
};
