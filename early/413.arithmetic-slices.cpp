/*
 * [413] Arithmetic Slices
 *
 * https://leetcode.com/problems/arithmetic-slices
 *
 * Medium (54.66%)
 * Total Accepted:    21300
 * Total Submissions: 38964
 * Testcase Example:  '[1,2,3,4]'
 *
 * A sequence of number is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 * 
 * For example, these are arithmetic sequence:
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * 
 * The following sequence is not arithmetic. 1, 1, 2, 5, 7 
 * 
 * 
 * A zero-indexed array A consisting of N numbers is given. A slice of that
 * array is any pair of integers (P, Q) such that 0 <= P < Q < N.
 * 
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 * ⁠   A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this
 * means that P + 1 < Q.
 * 
 * The function should return the number of arithmetic slices in the array
 * A. 
 * 
 * 
 * Example:
 * 
 * A = [1, 2, 3, 4]
 * 
 * return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3,
 * 4] itself.
 * 
 */
class Solution {
public:
    int getCount(int len){
        if(len<3){
            return 0;
        }
        
        return (len-2)*(len-1)/2;
    }
    
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3){
            return 0;
        }
        
        int begin = 0;
        int diff = A[1] - A[0];
        int res = 0;
        
        int d;
        for(int i=2;i<A.size();i++){
            d = A[i] - A[i-1];
            if(d!=diff){
                //begin .. (i - 1)
                res += getCount(i - begin);
                diff = d;
                begin = i-1;
            }
        }
        
        //begin .. A.size() - 1
        if(d==diff){
            res += getCount(A.size()-begin);
        }
        
        return res;
    }
};
