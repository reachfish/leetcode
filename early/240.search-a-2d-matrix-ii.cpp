/*
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii
 *
 * Medium (38.23%)
 * Total Accepted:    75885
 * Total Submissions: 198485
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * 
 * 
 * For example,
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * Given target = 20, return false.
 */
class Solution {
public:
    bool search(vector<vector<int> >& matrix, int target, int r1, int r2, int c1, int c2){
        if(r1>r2||c1>c2){
            return false;
        }
        
        int r = (r1+r2)/2;
        int c = (c1+c2)/2;
        
        if(matrix[r][c]==target){
            return true;
        }
        else if(matrix[r][c]<target){
            return search(matrix, target, r+1, r2, c1, c2) || search(matrix, target, r1, r, c+1, c2);
        }
        else{
            return search(matrix, target, r1, r-1, c1, c2) || search(matrix, target, r, r2, c1, c-1);
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0){
            return false;
        }
        
        int n = matrix[0].size();
        if(n==0){
            return false;
        }
        
        return search(matrix, target, 0, m-1, 0, n-1);
    }
};
