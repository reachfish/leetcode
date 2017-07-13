/*
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii
 *
 * Hard (44.42%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '1'
 *
 * Follow up for N-Queens problem.
 * 
 * Now, instead outputting board configurations, return the total number of
 * distinct solutions.
 * 
 * 
 */
class Solution {
public:
    int totalNQueens(int n) {
		if(n<=0) { return 0; }        

		vector<int> pos(n, -n);
		int count = 0;

		dfs(0, pos, count);

		return count;
    }

	void dfs(int i, vector<int>& pos, int& count){
		int n = pos.size();
		if(i==n){
			count++;
			return;
		}

		for(int j=0;j<n;j++){
			bool ok = true;
			for(int k=0; k<i; k++){
				if(pos[k]==j || pos[k]==j+i-k || pos[k]==j-i+k){
					ok = false;
					break;
				}
			}

			if(ok){
				pos[i] = j;
				dfs(i+1, pos, count);
				pos[i] = -n;
			}
		}
	}
};
