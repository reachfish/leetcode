/*
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix
 *
 * Medium (32.82%)
 * Total Accepted:    6666
 * Total Submissions: 20311
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * Example 1: 
 * Input:
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * Output:
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * 
 * 
 * Example 2: 
 * Input:
 * 
 * 0 0 0
 * 0 1 0
 * 1 1 1
 * 
 * Output:
 * 
 * 0 0 0
 * 0 1 0
 * 1 2 1
 * 
 * 
 * 
 * Note:
 * 
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 * 
 * 
 * 
 */

class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()){
            return vector<vector<int>>();
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int> > q;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!matrix[i][j]){
                    result[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        
        int dirs[][2]  = { {-1,0}, {1,0}, {0,-1}, {0,1} };
        
        while(!q.empty()){
            pair<int, int> pos = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x = pos.first;
                int y = pos.second;
                int r = x + dirs[i][0];
                int c = y + dirs[i][1];
                
                if(r < 0 || r >= rows || c< 0 || c >= cols || result[r][c] <= result[x][y] + 1)
                    continue;
                    
                result[r][c] = result[x][y] + 1;
                q.push(make_pair(r,c));
            } 
        }
        
        return result;
    }
};
