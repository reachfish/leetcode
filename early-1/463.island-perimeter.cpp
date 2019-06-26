/*
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter
 *
 * Easy (57.02%)
 * Total Accepted:    41350
 * Total Submissions: 72512
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given a map in form of a two-dimensional integer grid where 1
 * represents land and 0 represents water. Grid cells are connected
 * horizontally/vertically (not diagonally). The grid is completely surrounded
 * by water, and there is exactly one island (i.e., one or more connected land
 * cells). The island doesn't have "lakes" (water inside that isn't connected
 * to the water around the island). One cell is a square with side length 1.
 * The grid is rectangular, width and height don't exceed 100. Determine the
 * perimeter of the island.
 * 
 * Example:
 * 
 * [[0,1,0,0],
 * ⁠[1,1,1,0],
 * ⁠[0,1,0,0],
 * ⁠[1,1,0,0]]
 * 
 * Answer: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 * 
 * 
 * 
 */
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty()) { return 0; }
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int dirs[][2] = {{1,0},{-1,0},{0,1}, {0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]) continue;
                
                for(int k=0;k<4;k++){
                    int x = i + dirs[k][0];
                    int y = j + dirs[k][1];
                    
                    if(x<0||x>=m||y<0||y>=n||!grid[x][y]) { count++; }
                }
            }
        }
        
        return count;
    }
};
