/*
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii
 *
 * Medium (31.46%)
 * Total Accepted:    101739
 * Total Submissions: 323440
 * Testcase Example:  '[[0]]'
 *
 * Follow up for "Unique Paths":
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * 
 * [
 * ⁠ [0,0,0],
 * ⁠ [0,1,0],
 * ⁠ [0,0,0]
 * ]
 * 
 * The total number of unique paths is 2.
 * 
 * Note: m and n will be at most 100.
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()){
            return 0;
        }
        
        int a[100][100] = {0};
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(n==0){
            return 0;
        }
        
        a[0][0] = obstacleGrid[0][0]==0 ?  1 : 0;
        
        for(int i=1;i<m;i++){
            a[i][0] = a[i-1][0] == 1 && obstacleGrid[i][0] == 0 ? 1 : 0;
        }
        
        for(int j=1;j<n;j++){
            a[0][j] = a[0][j-1] == 1 && obstacleGrid[0][j] == 0 ? 1 : 0;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                a[i][j] = obstacleGrid[i][j] == 0 ? a[i-1][j] + a[i][j-1] : 0;
            }
        }
        
        return a[m-1][n-1];
    }
};
