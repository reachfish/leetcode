/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle
 *
 * Easy (38.05%)
 * Total Accepted:    129741
 * Total Submissions: 340953
 * Testcase Example:  '0'
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 * 
 * 
 * For example, given numRows = 5,
 * Return
 * 
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if(numRows<=0) { return res; }
        res.push_back(vector<int>(1,1));
        
        for(int i=1;i<numRows;i++){
            vector<int> v;
            v.push_back(1);
            for(int j=1;j<res[i-1].size();j++){
                v.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            v.push_back(1);
            res.push_back(v);
        }
        
        return res;
    }
};
