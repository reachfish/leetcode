/*
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum
 *
 * Medium (38.09%)
 * Total Accepted:    110625
 * Total Submissions: 290428
 * Testcase Example:  '[[0]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 */
class Solution {
public:
    int min(int a, int b){
        return a < b ? a : b;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0||grid[0].size()==0){
            return 0;
        }
        
        int cols = grid[0].size();
        int res[2][cols];
        
        int sum = 0;
        int flag = 0;
        for(int i=0;i<cols;i++){
            sum += grid[0][i];
            res[0][i] = sum;
        }
        
        for(int i=1;i<grid.size();i++){
            int last = flag;
            flag = 1 - flag;
            
            res[flag][0] = res[last][0] + grid[i][0];
            for(int j=1;j<cols;j++){
                res[flag][j] = min(res[flag][j-1], res[last][j]) + grid[i][j];
            }
        }
        
        return res[flag][cols-1];
    }
};
