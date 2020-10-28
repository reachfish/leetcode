/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (37.04%)
 * Likes:    2455
 * Dislikes: 173
 * Total Accepted:    382.4K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [], target = 0
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 0 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }

        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }

        int i = 0;
        int j = m * n - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            int v   = matrix[mid / n][mid % n];
            if (v == target) {
                return true;
            } else if (v < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return false;
    }
};
// @lc code=end
