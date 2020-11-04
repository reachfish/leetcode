/*
 * [629] K Inverse Pairs Array
 *
 * https://leetcode.com/problems/k-inverse-pairs-array
 *
 * Medium (23.19%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '3\n0'
 *
 * 
 * Given two integers n and k, find how many different arrays consist of
 * numbers from 1 to n such that there are exactly k inverse pairs. 
 * 
 * 
 * We define an inverse pair as following:
 * For ith and jth element in the array, if i < j and a[i] > a[j] then it's an
 * inverse pair; Otherwise, it's not.
 * 
 * 
 * 
 * Since the answer may very large, the answer should be modulo 109 + 7.
 * 
 * 
 * Example 1:
 * 
 * Input: n = 3, k = 0
 * Output: 1
 * Explanation: 
 * Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0
 * inverse pair.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: n = 3, k = 1
 * Output: 2
 * Explanation: 
 * The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
 * 
 * 
 * 
 * Note:
 * 
 * The integer n is in the range [1, 1000] and k is in the range [0, 1000].
 * 
 * 
 */
class Solution {
public:
	int kInversePairs(int n, int k) {
		if(k < 0 || n<=0) { return 0; }    
		int tmp[k+1], dp[k+1];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		const int m = pow(10, 9) + 7;
		for(int i=2;i<=n;i++)
		{   
			for(int j=0;j<=k;j++)
			{   
				tmp[j] = dp[j];
			}   

			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			for(int j=1;j<=k && j<=i*(i-1)/2;j++)
			{   
				int v = 0;
				for(int s=j-i+1>0?j-i+1:0;s<=j;s++)
				{   
					v = (v+tmp[s]) % m;
				}   

				dp[j] = v;
			} 

		}   

		return dp[k];  
	}
};
