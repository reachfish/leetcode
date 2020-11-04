/*
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths
 *
 * Medium (40.53%)
 * Total Accepted:    137403
 * Total Submissions: 339015
 * Testcase Example:  '1\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * 
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * 
 * 
 * Note: m and n will be at most 100.
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        int a[100][100] = {0};
        for(int i=0;i<100;i++){
            a[i][0] = 1;
            a[0][i] = 1;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        
        return a[m-1][n-1];
    }
};
