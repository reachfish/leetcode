/*
 * [718] Maximum Length of Repeated Subarray
 *
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray
 *
 * algorithms
 * Medium (38.69%)
 * Total Accepted:    5.4K
 * Total Submissions: 13.6K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * Given two integer arrays A and B, return the maximum length of an subarray
 * that appears in both arrays.
 * 
 * Example 1:
 * 
 * Input:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * Output: 3
 * Explanation: 
 * The repeated subarray with maximum length is [3, 2, 1].
 * 
 * 
 * 
 * Note:
 * 
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 * 
 * 
 */
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
		int m = A.size();
		int n = B.size();
		if(m==0||n==0){
			return 0;
		}

		int len = 0;
		int a[m][n];
		memset(a, 0, sizeof(a));

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(A[i]==B[j]){
					int d = (i && j) ? a[i-1][j-1] + 1 : 1;
					a[i][j] = d;
					if(d > len){
						len = d;
					}
				}
			}
		}

		return len;
    }
};
