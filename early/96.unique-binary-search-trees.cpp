/*
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees
 *
 * Medium (40.57%)
 * Total Accepted:    119317
 * Total Submissions: 294107
 * Testcase Example:  '1'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1...n?
 * 
 * 
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 * 
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
class Solution {
public:
    int numTrees(int n) {
        if(n<0) { return 0; }
        
        int dp[n+1];
        dp[0] = 1;
        
        for(int i=1;i<=n;i++){
           int m = 0;
           for(int j=1;j<=i;j++){
               m += dp[j-1] * dp[i-j];
           }
           dp[i] = m;
        }
        
        return dp[n];
    }
};
