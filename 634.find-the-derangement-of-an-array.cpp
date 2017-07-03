/*
 * [634] Find the Derangement of An Array
 *
 * https://leetcode.com/problems/find-the-derangement-of-an-array
 *
 * Medium (26.43%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '1'
 *
 * 
 * In combinatorial mathematics, a derangement is a permutation of the elements
 * of a set, such that no element appears in its original position.
 * 
 * 
 * 
 * There's originally an array consisting of n integers from 1 to n in
 * ascending order, you need to find the number of derangement it can
 * generate.
 * 
 * 
 * 
 * Also, since the answer may be very large, you should return the output mod
 * 109 + 7.
 * 
 * 
 * Example 1:
 * 
 * Input: 3
 * Output: 2
 * Explanation: The original array is [1,2,3]. The two derangements are [2,3,1]
 * and [3,1,2].
 * 
 * 
 * 
 * Note:
 * n is in the range of [1, 106].
 * 
 */
class Solution {
public:
    int findDerangement(int n) {
		if(n <= 1) { return 0; }        
		const int MOD = pow(10, 9) + 7;

		int a = 0;
		int b = 1;

		for(int i=3;i<=n;i++){
			int c = (1L * (i-1) * ((a+b)%MOD)) % MOD;
			a = b;
			b = c;
		}

		return b;
    }
};
