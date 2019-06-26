/*
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens
 *
 * Hard (30.58%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 * 
 * [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 
 */
class Solution {
public:
	void dfs(int i, vector<vector<string>>& res, vector<string> &s){
		int n = s.size();
		if(i==n){
			res.push_back(s);
			return;
		}

		for(int j=0;j<n;j++){
			bool ok = true;
			for(int k=0;k<i;k++){
				if(s[k][j] == 'Q' || (j+i-k<n && s[k][j+i-k]=='Q') || (j-i+k>=0 && s[k][j-i+k]=='Q')){
					ok = false;
					break;
				}
			}

			if(ok){
				s[i][j] = 'Q';
				dfs(i+1, res, s);
				s[i][j] = '.';
			}
		}
	}

    vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		if(n<=0) { return res; }

		vector<string> s(n, string(n, '.'));

		dfs(0, res, s);

		return res;
    }
};
