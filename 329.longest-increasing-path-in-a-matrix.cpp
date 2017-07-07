/*
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix
 *
 * Hard (36.01%)
 * Total Accepted:    35269
 * Total Submissions: 97942
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * 
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 * 
 * 
 * Example 1:
 * 
 * nums = [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 * 
 * 
 * Return 4
 * 
 * The longest increasing path is [1, 2, 6, 9].
 * 
 * 
 * Example 2:
 * 
 * nums = [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ]
 * 
 * 
 * 
 * 
 * Return 4
 * 
 * The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not
 * allowed.
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
const int dirs[4][2] =  { {1,0}, {-1,0}, {0,1}, {0, -1} };

class Solution {
public:

	int dfs(const vector<vector<int>> &matrix, int i, int j, vector<vector<int>>& cache){
		if(cache[i][j] > 0){
			return cache[i][j];
		}

		int m = matrix.size();
		int n = matrix[0].size();

		int max = 0;
		for(int k=0; k<4; k++){
			int x = i + dirs[k][0];
			int y = j + dirs[k][1];

			if(x>=0 && x<m && y>=0 && y<n && matrix[i][j] < matrix[x][y]){
				int val = dfs(matrix, x, y, cache);
				max = max > val ? max : val;
			}
		}

		int len = max + 1;
		cache[i][j] = len;

		return len;
	}

    int longestIncreasingPath(vector<vector<int>>& matrix) {
		if(matrix.empty() || matrix[0].empty()) { return 0; }

		int m = matrix.size();
		int n = matrix[0].size();

		vector<vector<int>> cache(m, vector<int>(n, 0));

		int max = 0;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				int val = dfs(matrix, i, j, cache);
				max = max > val ? max : val;
			}
		}

		return max;
    }
};
