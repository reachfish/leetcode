/*
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii
 *
 * Medium (39.11%)
 * Total Accepted:    79703
 * Total Submissions: 203769
 * Testcase Example:  '0'
 *
 * Given an integer n, generate a square matrix filled with elements from 1 to
 * n2 in spiral order.
 * 
 * 
 * For example,
 * Given n = 3,
 * 
 * You should return the following matrix:
 * 
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n<1) { return vector<vector<int> >(); }
        
        int dirs[][2] = { {0,1}, {1, 0}, {0, -1}, {-1, 0} }; 
        int dir_idx = 0;
        int i = 0, j = 0;
        int x = dirs[dir_idx][0];
        int y = dirs[dir_idx][1];
        vector<vector<int> > res(n, vector<int>(n, 0));
        for(int k=1;k<=n*n;k++){
            if(!(i>=0 && i< n && j >=0 && j< n && !res[i][j])){
                i -= x;
                j -= y;
                
                dir_idx = (dir_idx+1) % 4;
                x = dirs[dir_idx][0];
                y = dirs[dir_idx][1];
                
                i += x;
                j += y;
            }
            
            res[i][j] = k;
            i += x;
            j += y;
        }
        
        return res;
    }
};
