/*
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix
 *
 * Medium (35.18%)
 * Total Accepted:    122415
 * Total Submissions: 347927
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
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
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * 
 * 
 * Given target = 3, return true.
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) { return false; }
        if(matrix[0].empty()) { return false; }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0;
        int j = m * n - 1;
        
        while(i<j){
            int mid = i + (j-i)/2;
            int diff = matrix[mid/n][mid%n] - target;
            if(diff == 0) { return true; }
            if(diff > 0) { j = mid; }
            else { i = mid + 1; }
        }
        
        return matrix[i/n][i%n] == target;
    }
};
