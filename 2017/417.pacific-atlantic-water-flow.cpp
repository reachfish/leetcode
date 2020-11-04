/*
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow
 *
 * Medium (33.35%)
 * Total Accepted:    13485
 * Total Submissions: 40431
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * Given an m x n matrix of non-negative integers representing the height of
 * each unit cell in a continent, the "Pacific ocean" touches the left and top
 * edges of the matrix and the "Atlantic ocean" touches the right and bottom
 * edges.
 * 
 * Water can only flow in four directions (up, down, left, or right) from a
 * cell to another one with height equal or lower.
 * 
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 * 
 * Note:
 * 
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 * 
 * 
 * Example:
 * 
 * Given the following 5x5 matrix:
 * 
 * ⁠ Pacific ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * Atlantic
 * 
 * Return:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
 * parentheses in above matrix).
 * 
 * 
 */
class Solution {
public:
    void updateFlag(const vector<vector<int>>& matrix, vector<vector<int>>& flag, bool isUp){
        int tag = isUp ? 1 : 2;
        int m = matrix.size();
        int n = matrix[0].size();
        
        queue<pair<int, int>> que;
        
        int col = isUp ? 0 : n-1;
        for(int i=0;i<m;i++){
            flag[i][col] |= tag;
            que.push(make_pair(i, col));
        }
        
        int row = isUp ? 0 : m-1;
        for(int j=0;j<n;j++){
            if(!(flag[row][j]&tag)){
                flag[row][j] |= tag;
                que.push(make_pair(row, j));
            }
        }
        
        int dirs[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!que.empty()){
            pair<int,int> p = que.front();
            que.pop();
            int val = matrix[p.first][p.second];
            for(int k=0;k<4;k++){
                int i = p.first + dirs[k][0];
                int j = p.second + dirs[k][1];
                if(i>=0 && i<m && j>=0 && j < n && !(flag[i][j]&tag) && matrix[i][j] >= val){
                    flag[i][j] |= tag;
                    que.push(make_pair(i, j));
                }
            }
        }
    }
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        
        if(matrix.empty()||matrix[0].empty()) { return res; }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> flag(m, vector<int>(n, 0));
        updateFlag(matrix, flag, true);
        updateFlag(matrix, flag, false);
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                //printf("(%d,%d):%d\n", i,j, flag[i][j]);
                if(flag[i][j]==3){
                    res.push_back(make_pair(i, j));
                }
            }
        
        return res;
    }
};
