/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands
 *
 * Medium (33.90%)
 * Total Accepted:    105130
 * Total Submissions: 310117
 * Testcase Example:  '["11110","11010","11000","00000"]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 11110110101100000000
 * Answer: 1
 * Example 2:
 * 11000110000010000011
 * Answer: 3
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0) { return 0; }
        int n = grid[0].size();
        if(n == 0) { return 0; }
        
        int count = 0;
        
        int dirs[][2] = { {-1, 0}, { 1, 0}, {0, -1}, {0, 1} };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] != '1') { continue; }
                count++;
                
                queue<pair<int, int>> que;
                que.push(make_pair(i, j));
                grid[i][j] = '9';
                
                while(!que.empty()){
                    pair<int, int> pos = que.front();
                    que.pop();
                    
                    for(int k = 0;k<4;k++){
                        int x = pos.first + dirs[k][0];
                        int y = pos.second + dirs[k][1];
                        if(x>=0 && x < m && y >= 0 && y <n && grid[x][y] == '1') {
                            que.push(make_pair(x, y));
                            grid[x][y] = '9';
                        }
                    }
                }
            }
        }
        
        
        return count;
    }
};
