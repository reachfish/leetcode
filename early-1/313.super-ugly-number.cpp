/*
 * [313] Super Ugly Number
 *
 * https://leetcode.com/problems/super-ugly-number
 *
 * Medium (37.37%)
 * Total Accepted:    35472
 * Total Submissions: 94926
 * Testcase Example:  '1\n[2,3,5]'
 *
 * 
 * ⁠   Write a program to find the nth super ugly number.
 * 
 * 
 * 
 * ⁠   Super ugly numbers are positive numbers whose all prime factors are in
 * the given prime list
 * ⁠   primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28,
 * 32]
 * ⁠is the sequence of the first 12 super ugly numbers given primes
 * ⁠   = [2, 7, 13, 19] of size 4.
 * 
 * 
 * 
 * ⁠   Note:
 * ⁠   (1) 1 is a super ugly number for any given primes.
 * ⁠   (2) The given numbers in primes are in ascending order.
 * ⁠   (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 * ⁠   (4) The nth super ugly number is guaranteed to fit in a 32-bit signed
 * integer.
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    
    static bool compare(const pair<long, int>& v1, const pair<long, int>& v2){
        return v1.first > v2.first;
    }
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n<=0){
            return -1;
        }
        
        vector<pair<long, int> > heap;
        heap.push_back(make_pair(1,0));
        make_heap(heap.begin(), heap.end(), Solution::compare);
        
        int res = 1;
        for(int i=1;i<=n;i++){
            pair<long, int> elem = heap.front();
            pop_heap(heap.begin(), heap.end(), Solution::compare);
            heap.pop_back();
            
            res = elem.first;
            
            for(int j=elem.second;j<primes.size();j++){
                heap.push_back(make_pair(elem.first * primes[j]*1L, j));
                push_heap(heap.begin(), heap.end(), Solution::compare);
            }
        }
        
        return res;
    }
};
