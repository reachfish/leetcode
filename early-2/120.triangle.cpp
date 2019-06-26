/*
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle
 *
 * Medium (33.37%)
 * Total Accepted:    103442
 * Total Submissions: 309980
 * Testcase Example:  '[[-10]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * 
 * For example, given the following triangle
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * 
 * 
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */
class Solution {
public:
    int min(int a, int b) { 
        return a < b ? a : b; 
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) { return 0; }        
        vector<int> v;
        v.push_back(triangle[0][0]);
        for(int i=1;i<triangle.size();i++){
            vector<int> tmp(i+1);
            for(int j=0;j<=i;j++){
                tmp[j] += min(j ? v[j-1] : INT_MAX, j==i ? INT_MAX : v[j]) + triangle[i][j];
            }

            v = tmp;
        }

        int m = INT_MAX;
        for(auto n : v) { m = min(m, n); }

        return m;
    }
};
