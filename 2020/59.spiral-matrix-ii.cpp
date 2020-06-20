/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (52.97%)
 * Likes:    928
 * Dislikes: 107
 * Total Accepted:    189.2K
 * Total Submissions: 357K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int lm = 0;
        int rm = n - 1;
        int um = 0;
        int dm = n - 1;
        int k  = 1;
        int i  = 0;
        int j  = 0;
        for (;;) {
            while (j <= rm) {
                result[i][j++] = k++;
            }
            j--;
            i++;
            um++;
            if (i > dm) {
                break;
            }
            while (i <= dm) {
                result[i++][j] = k++;
            }
            i--;
            j--;
            rm--;
            if (j < lm) {
                break;
            }
            while (j >= lm) {
                result[i][j--] = k++;
            }
            j++;
            i--;
            dm--;
            if (i < um) {
                break;
            }
            while (i >= um) {
                result[i--][j] = k++;
            }
            i++;
            j++;
            lm++;
            if (j > rm) {
                break;
            }
        }

        return result;
    }
};
// @lc code=end
