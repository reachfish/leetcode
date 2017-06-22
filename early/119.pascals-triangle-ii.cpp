/*
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii
 *
 * Easy (36.29%)
 * Total Accepted:    114048
 * Total Submissions: 314300
 * Testcase Example:  '0'
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 * 
 * 
 * For example, given k = 3,
 * Return [1,3,3,1].
 * 
 * 
 * 
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex<0) { return vector<int>(); }
        
        rowIndex++;
        vector<vector<int> > dp(2, vector<int>(rowIndex,0));
        int flag = 0;
        dp[0][0] = 1;
        
        for(int i=2;i<=rowIndex;i++){
            flag = 1 - flag;
            
            int j = 0;
            dp[flag][j++] = 1;
            for(int k=1;k<=rowIndex-2;k++, j++){
                dp[flag][j] = dp[1-flag][j-1] + dp[1-flag][j];
            }
            dp[flag][j++] = 1;
        }
        
        return dp[flag];
    }
};
